param(
  [string]$prob     = "letter",
  [int]   $iters    = 1000,
  [int]   $nmax     = 50,
  [long]  $baseSeed = 0
)

# names (convention)
$fastCpp   = "$prob.cpp"
$bruteCpp  = "${prob}_brute.cpp"
$genCpp    = "gen_$prob.cpp"
$genPy     = "gen_$prob.py"
$genExe    = "gen_$prob.exe"
$fastExe   = "$prob.exe"
$bruteExe  = "${prob}_brute.exe"
$checkCpp  = "checker_$prob.cpp"
$checkExe  = "checker_$prob.exe"

$inFile    = "$prob.in"
$fastOut   = "${prob}_fast.out"
$bruteOut  = "${prob}_brute.out"

function Compile-If([string]$src, [string]$out) {
  if (Test-Path $src) {
    Write-Host "[build] $src -> $out"
    $cmds = @(
      @("g++",    "-std=c++20","-O2",$src,"-o",$out),
      @("clang++","-std=c++20","-O2",$src,"-o",$out)
    )
    $ok = $false
    foreach ($c in $cmds) {
      try {
        & $c[0] $c[1..($c.Length-1)] 2>$null
        if (Test-Path $out) { $ok = $true; break }
      } catch { }
    }
    if (-not $ok) { throw "failed to compile $src (need g++ or clang++)" }
  }
}

# build fast & brute
Compile-If $fastCpp  $fastExe
Compile-If $bruteCpp $bruteExe
if (-not (Test-Path $fastExe))  { throw "missing $fastExe and no $fastCpp to build" }
if (-not (Test-Path $bruteExe)) { throw "missing $bruteExe and no $bruteCpp to build" }

# generator (prefer compiled .cpp -> .exe; else .exe; else .py)
if (Test-Path $genCpp) { Compile-If $genCpp $genExe }
if (Test-Path $genExe) { $genCmd = @(".\${genExe}") }
elseif (Test-Path $genPy) { $genCmd = @("python", $genPy) }
else { throw "provide generator: $genCpp OR $genPy OR prebuilt $genExe" }

# optional checker
if (Test-Path $checkCpp) { Compile-If $checkCpp $checkExe }
$checkMode = (Test-Path $checkExe) ? "custom" : "diff"

Write-Host "[stress] PROB=$prob ITERS=$iters NMAX=$nmax BASE_SEED=$baseSeed CHECK=$checkMode"

for ($it = 1; $it -le $iters; $it++) {
  $seed = $baseSeed + $it

  # generate -> input file
  & $genCmd[0] $genCmd[1..100] --seed=$seed --nmax=$nmax | Out-File -Encoding ASCII $inFile

  # run fast & brute
  cmd /c "type `"$inFile`" | `"$fastExe`" > `"$fastOut`""
  cmd /c "type `"$inFile`" | `"$bruteExe`" > `"$bruteOut`""

  # compare
  if ($checkMode -eq "custom") {
    & ".\${checkExe}" $inFile $fastOut $bruteOut | Out-Null
    if ($LASTEXITCODE -ne 0) {
      Write-Host "================= MISMATCH ================="
      Write-Host "Iter: $it  Seed: $seed"
      Write-Host "Input:   $inFile"
      Write-Host "Fast:    $fastOut"
      Write-Host "Brute:   $bruteOut"
      exit 0
    }
  } else {
    # whitespace-insensitive compare via fc.exe /w (0 = equal)
    cmd /c "fc /w `"$bruteOut`" `"$fastOut`"" | Out-Null
    if ($LASTEXITCODE -ne 0) {
      Write-Host "================= MISMATCH ================="
      Write-Host "Iter: $it  Seed: $seed"
      Write-Host "Input:   $inFile"
      Write-Host "Fast:    $fastOut"
      Write-Host "Brute:   $bruteOut"
      Write-Host "------------------- DIFF -------------------"
      cmd /c "fc /w `"$bruteOut`" `"$fastOut`""
      exit 0
    }
  }

  if ($it % 100 -eq 0) { Write-Host "[ok] $it" }
}

Write-Host "[stress] All $iters iterations matched."
