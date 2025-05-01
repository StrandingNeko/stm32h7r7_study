# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot"
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/build"
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot"
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/tmp"
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/Src/bootloader_Boot-stamp"
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/Src"
  "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/Src/bootloader_Boot-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/Src/bootloader_Boot-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/2.Git/github/stm32h7r7_study/2.software/bootloader/Boot/Src/bootloader_Boot-stamp${cfgdir}") # cfgdir has leading slash
endif()
