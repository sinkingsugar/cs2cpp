// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

/*============================================================
**
** 
** 
**
**
** Purpose: Exception for accessing a path that doesn't exist.
**
**
===========================================================*/
using System;

namespace System.IO {
    /*
     * Thrown when trying to access a directory that doesn't exist on disk.
     * From COM Interop, this exception is thrown for 2 HRESULTS: 
     * the Win32 errorcode-as-HRESULT ERROR_PATH_NOT_FOUND (0x80070003) 
     * and STG_E_PATHNOTFOUND (0x80030003).
     */
    [Serializable]
    [System.Runtime.InteropServices.ComVisible(true)]
    public class DirectoryNotFoundException : IOException {
        public DirectoryNotFoundException() 
            : base(Environment.GetResourceString("Arg_DirectoryNotFoundException")) {
        }
    
        public DirectoryNotFoundException(String message) 
            : base(message) {
        }
    
        public DirectoryNotFoundException(String message, Exception innerException) 
            : base(message, innerException) {
        }
    }
}
