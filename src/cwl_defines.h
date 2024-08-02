// MIT License
// 
// Copyright (c) 2024 icantplay
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _CWL_DEFINES_H_
#define _CWL_DEFINES_H_

#ifdef _WIN32 // Platform is windows
    #define CWL_PLAT_WIN
#elif __linux__ // Platform is linux
    #define CWL_PLAT_LINUX
#endif // _WIN32

#ifdef CWL_EXPORT
    #ifdef _WIN32
        #define CWL_API __declspec(dllexport)
    #elif linux
        #define CWL_API __attribute__((visibility("default")))
    #endif // _WIN32
#else
    #ifdef _WIN32
        #define CWL_API __declspec(dllimport)
    #elif linux
        #define CWL_API
    #endif // _WIN32
#endif // CWL_EXPORT

#endif // _CWL_DEFINES_H_