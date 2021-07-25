# Blink

After pulling repo - 2 steps 
1. delete file /out/CMakeCache.txt
2. Run CMake: Clean Rebuild from command pallet
-> Build should be successful, and ready to start making changes


Be sure .gitignore from Azure Sphere: Generate New Project has been removed. 
The /out/ folder holds is important information

Error of GPIO in use (etc) was fixed by by running azsphere device recover
(probably a better way -> but works for now)
