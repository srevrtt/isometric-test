$ProgressPreference = 'SilentlyContinue'

Write-Host "Info: Fetching dependencies for mingw..." -ForegroundColor blue

$null = New-Item -Path "external" -Name "lib" -ItemType "directory" -Force
$null = New-Item -Path "bin" -Name "lib" -ItemType "directory" -Force

Write-Host "Info: Downloading SDL2..." -ForegroundColor blue
Invoke-WebRequest "https://github.com/libsdl-org/SDL/releases/download/release-2.26.4/SDL2-devel-2.26.4-mingw.zip" -OutFile external/sdl.zip

Write-Host "Info: Downloading SDL2_image..." -ForegroundColor blue
Invoke-WebRequest "https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-devel-2.6.3-mingw.zip" -OutFile external/sdl_image.zip

Write-Host "Info: Downloading SDL2_ttf..." -ForegroundColor blue
Invoke-WebRequest "https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-devel-2.20.2-mingw.zip" -OutFile external/sdl_ttf.zip

Write-Host "Info: Extracting..." -ForegroundColor blue

Expand-Archive -Path external/sdl.zip -DestinationPath external/SDL2_
Expand-Archive -Path external/sdl_image.zip -DestinationPath external/SDL2_image
Expand-Archive -Path external/sdl_ttf.zip -DestinationPath external/SDL2_ttf

Write-Host "Info: Copying..." -ForegroundColor blue

# Move headers
Move-Item -Path external/SDL2_/SDL2-2.26.4/x86_64-w64-mingw32/include/SDL2 -Destination external/SDL2
Move-Item -Path external/SDL2_image/SDL2_image-2.6.3/x86_64-w64-mingw32/include/SDL2/SDL_image.h -Destination external/SDL2/SDL_image.h
Move-Item -Path external/SDL2_ttf/SDL2_ttf-2.20.2/x86_64-w64-mingw32/include/SDL2/SDL_ttf.h -Destination external/SDL2/SDL_ttf.h

# Move DLLs
Move-Item -Path external/SDL2_/SDL2-2.26.4/x86_64-w64-mingw32/bin/SDL2.dll -Destination bin/SDL2.dll
Move-Item -Path external/SDL2_image/SDL2_image-2.6.3/x86_64-w64-mingw32/bin/SDL2_image.dll -Destination bin/SDL2_image.dll
Move-Item -Path external/SDL2_ttf/SDL2_ttf-2.20.2/x86_64-w64-mingw32/bin/SDL2_ttf.dll -Destination bin/SDL2_ttf.dll

# Move static libraries
Move-Item -Path external/SDL2_/SDL2-2.26.4/x86_64-w64-mingw32/lib/*.a -Destination external/lib
Move-Item -Path external/SDL2_/SDL2-2.26.4/x86_64-w64-mingw32/lib/*.la -Destination external/lib

Move-Item -Path external/SDL2_image/SDL2_image-2.6.3/x86_64-w64-mingw32/lib/*.a -Destination external/lib
Move-Item -Path external/SDL2_image/SDL2_image-2.6.3/x86_64-w64-mingw32/lib/*.la -Destination external/lib

Move-Item -Path external/SDL2_ttf/SDL2_ttf-2.20.2/x86_64-w64-mingw32/lib/*.a -Destination external/lib
Move-Item -Path external/SDL2_ttf/SDL2_ttf-2.20.2/x86_64-w64-mingw32/lib/*.la -Destination external/lib

# Clean up
Write-Host "Info: Cleaning up..." -ForegroundColor blue

Remove-Item external/sdl_image.zip
Remove-Item external/sdl_ttf.zip
Remove-Item external/sdl.zip
Remove-Item external/SDL2_ -Recurse
Remove-Item external/SDL2_image -Recurse
Remove-Item external/SDL2_ttf -Recurse

Write-Host "Success!" -ForegroundColor green
