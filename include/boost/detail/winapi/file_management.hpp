//  file_management.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_FILE_MANAGEMENT_HPP
#define BOOST_DETAIL_WINAPI_FILE_MANAGEMENT_HPP

#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/security.hpp>
#include <boost/detail/winapi/time.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
struct _OVERLAPPED;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
    CreateFileA(
        boost::detail::winapi::LPCSTR_ lpFileName,
        boost::detail::winapi::DWORD_ dwDesiredAccess,
        boost::detail::winapi::DWORD_ dwShareMode,
        ::_SECURITY_ATTRIBUTES* lpSecurityAttributes,
        boost::detail::winapi::DWORD_ dwCreationDisposition,
        boost::detail::winapi::DWORD_ dwFlagsAndAttributes,
        boost::detail::winapi::HANDLE_ hTemplateFile);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI    
    DeleteFileA(boost::detail::winapi::LPCSTR_ lpFileName);
struct _WIN32_FIND_DATAA;
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
    FindFirstFileA(boost::detail::winapi::LPCSTR_ lpFileName, ::_WIN32_FIND_DATAA* lpFindFileData);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    FindNextFileA(boost::detail::winapi::HANDLE_ hFindFile, ::_WIN32_FIND_DATAA* lpFindFileData);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    MoveFileExA(
        boost::detail::winapi::LPCSTR_ lpExistingFileName,
        boost::detail::winapi::LPCSTR_ lpNewFileName,
        boost::detail::winapi::DWORD_ dwFlags);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
    CreateFileW(
        boost::detail::winapi::LPCWSTR_ lpFileName,
        boost::detail::winapi::DWORD_ dwDesiredAccess,
        boost::detail::winapi::DWORD_ dwShareMode,
        ::_SECURITY_ATTRIBUTES* lpSecurityAttributes,
        boost::detail::winapi::DWORD_ dwCreationDisposition,
        boost::detail::winapi::DWORD_ dwFlagsAndAttributes,
        boost::detail::winapi::HANDLE_ hTemplateFile);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI    
    DeleteFileW(boost::detail::winapi::LPCWSTR_ lpFileName);
struct _WIN32_FIND_DATAW;
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI
    FindFirstFileW(boost::detail::winapi::LPCWSTR_ lpFileName, ::_WIN32_FIND_DATAW* lpFindFileData);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    FindNextFileW(boost::detail::winapi::HANDLE_ hFindFile, ::_WIN32_FIND_DATAW* lpFindFileData);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    MoveFileExW(
        boost::detail::winapi::LPCWSTR_ lpExistingFileName,
        boost::detail::winapi::LPCWSTR_ lpNewFileName,
        boost::detail::winapi::DWORD_ dwFlags);

BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    FindClose(boost::detail::winapi::HANDLE_ hFindFile);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    GetFileSizeEx(
        boost::detail::winapi::HANDLE_ hFile,
        ::_LARGE_INTEGER* lpFileSize);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    SetFileValidData(
        boost::detail::winapi::HANDLE_ hFile,
        boost::detail::winapi::LONGLONG_ ValidDataLength);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    SetEndOfFile(
        boost::detail::winapi::HANDLE_ hFile);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    LockFile(
        boost::detail::winapi::HANDLE_ hFile,
        boost::detail::winapi::DWORD_ dwFileOffsetLow,
        boost::detail::winapi::DWORD_ dwFileOffsetHigh,
        boost::detail::winapi::DWORD_ nNumberOfBytesToLockLow,
        boost::detail::winapi::DWORD_ nNumberOfBytesToLockHigh);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    UnlockFile(
        boost::detail::winapi::HANDLE_ hFile,
        boost::detail::winapi::DWORD_ dwFileOffsetLow,
        boost::detail::winapi::DWORD_ dwFileOffsetHigh,
        boost::detail::winapi::DWORD_ nNumberOfBytesToUnlockLow,
        boost::detail::winapi::DWORD_ nNumberOfBytesToUnlockHigh);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    LockFileEx(
        boost::detail::winapi::HANDLE_ hFile,
        boost::detail::winapi::DWORD_ dwFlags,
        boost::detail::winapi::DWORD_ dwReserved,
        boost::detail::winapi::DWORD_ nNumberOfBytesToLockLow,
        boost::detail::winapi::DWORD_ nNumberOfBytesToLockHigh,
        ::_OVERLAPPED* lpOverlapped);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    UnlockFileEx(
        boost::detail::winapi::HANDLE_ hFile,
        boost::detail::winapi::DWORD_ dwReserved,
        boost::detail::winapi::DWORD_ nNumberOfBytesToUnlockLow,
        boost::detail::winapi::DWORD_ nNumberOfBytesToUnlockHigh,
        ::_OVERLAPPED* lpOverlapped);
BOOST_SYMBOL_IMPORT boost::detail::winapi::BOOL_ WINAPI
    WriteFile(
        boost::detail::winapi::HANDLE_ hFile,
        boost::detail::winapi::LPCVOID_ lpBuffer,
        boost::detail::winapi::DWORD_ nNumberOfBytesToWrite,
        boost::detail::winapi::LPDWORD_ lpNumberOfBytesWritten,
        ::_OVERLAPPED* lpOverlapped);
}
#endif

namespace boost
{
namespace detail
{
namespace winapi
{
#if defined( BOOST_USE_WINDOWS_H )
#if !defined( BOOST_NO_ANSI_APIS )
using ::CreateFileA;
using ::DeleteFileA;
typedef ::WIN32_FIND_DATAA WIN32_FIND_DATAA_;
typedef ::PWIN32_FIND_DATAA PWIN32_FIND_DATAA_;
typedef ::LPWIN32_FIND_DATAA LPWIN32_FIND_DATAA_;
using ::FindFirstFileA;
using ::FindNextFileA;
using ::MoveFileExA;
#endif

using ::CreateFileW;
using ::DeleteFileW;
typedef ::WIN32_FIND_DATAW WIN32_FIND_DATAW_;
typedef ::PWIN32_FIND_DATAW PWIN32_FIND_DATAW_;
typedef ::LPWIN32_FIND_DATAW LPWIN32_FIND_DATAW_;
using ::FindFirstFileW;
using ::FindNextFileW;
using ::MoveFileExW;

using ::FindClose;
using ::GetFileSizeEx;
using ::SetFileValidData;
using ::SetEndOfFile;
using ::LockFile;
using ::UnlockFile;
using ::LockFileEx;
using ::UnlockFileEx;
using ::WriteFile;

#else

typedef struct _OVERLAPPED {
    ULONG_PTR_ Internal;
    ULONG_PTR_ InternalHigh;
    union {
        struct {
            DWORD_ Offset;
            DWORD_ OffsetHigh;
        };
        PVOID_  Pointer;
    };
    HANDLE_    hEvent;
} OVERLAPPED_, *LPOVERLAPPED_;

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ CreateFileA(
    LPCSTR_ lpFileName,
    DWORD_ dwDesiredAccess,
    DWORD_ dwShareMode,
    SECURITY_ATTRIBUTES_* lpSecurityAttributes,
    DWORD_ dwCreationDisposition,
    DWORD_ dwFlagsAndAttributes,
    HANDLE_ hTemplateFile)
{
    return ::CreateFileA(
        lpFileName,
        dwDesiredAccess,
        dwShareMode,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpSecurityAttributes),
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);
}

BOOST_FORCEINLINE BOOL_ DeleteFileA(LPCSTR_ lpFileName)
{
    return ::DeleteFileA(lpFileName);
}

typedef struct _WIN32_FIND_DATAA {
    DWORD_ dwFileAttributes;
    FILETIME_ ftCreationTime;
    FILETIME_ ftLastAccessTime;
    FILETIME_ ftLastWriteTime;
    DWORD_ nFileSizeHigh;
    DWORD_ nFileSizeLow;
    DWORD_ dwReserved0;
    DWORD_ dwReserved1;
    CHAR_   cFileName[ 260 ]; // MAX_PATH
    CHAR_   cAlternateFileName[ 14 ];
#ifdef _MAC
    DWORD_ dwFileType;
    DWORD_ dwCreatorType;
    WORD_  wFinderFlags;
#endif
} WIN32_FIND_DATAA_, *PWIN32_FIND_DATAA_, *LPWIN32_FIND_DATAA_;

BOOST_FORCEINLINE HANDLE_ FindFirstFileA(LPCSTR_ lpFileName, WIN32_FIND_DATAA_* lpFindFileData)
{
    return ::FindFirstFileA(lpFileName, reinterpret_cast< ::_WIN32_FIND_DATAA* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ FindNextFileA(HANDLE_ hFindFile, WIN32_FIND_DATAA_* lpFindFileData)
{
    return ::FindNextFileA(hFindFile, reinterpret_cast< ::_WIN32_FIND_DATAA* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ MoveFileExA(LPCSTR_ lpExistingFileName, LPCSTR_ lpNewFileName, DWORD_ dwFlags)
{
    return ::MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags);
}
#endif

BOOST_FORCEINLINE HANDLE_ CreateFileW(
    LPCWSTR_ lpFileName,
    DWORD_ dwDesiredAccess,
    DWORD_ dwShareMode,
    SECURITY_ATTRIBUTES_* lpSecurityAttributes,
    DWORD_ dwCreationDisposition,
    DWORD_ dwFlagsAndAttributes,
    HANDLE_ hTemplateFile)
{
    return ::CreateFileW(
        lpFileName,
        dwDesiredAccess,
        dwShareMode,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpSecurityAttributes),
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);
}

BOOST_FORCEINLINE BOOL_ DeleteFileW(LPCWSTR_ lpFileName)
{
    return ::DeleteFileW(lpFileName);
}

typedef struct _WIN32_FIND_DATAW {
    DWORD_ dwFileAttributes;
    FILETIME_ ftCreationTime;
    FILETIME_ ftLastAccessTime;
    FILETIME_ ftLastWriteTime;
    DWORD_ nFileSizeHigh;
    DWORD_ nFileSizeLow;
    DWORD_ dwReserved0;
    DWORD_ dwReserved1;
    WCHAR_  cFileName[ 260 ]; // MAX_PATH
    WCHAR_  cAlternateFileName[ 14 ];
#ifdef _MAC
    DWORD_ dwFileType;
    DWORD_ dwCreatorType;
    WORD_  wFinderFlags;
#endif
} WIN32_FIND_DATAW_, *PWIN32_FIND_DATAW_, *LPWIN32_FIND_DATAW_;

BOOST_FORCEINLINE HANDLE_ FindFirstFileW(LPCWSTR_ lpFileName, WIN32_FIND_DATAW_* lpFindFileData)
{
    return ::FindFirstFileW(lpFileName, reinterpret_cast< ::_WIN32_FIND_DATAW* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ FindNextFileW(HANDLE_ hFindFile, WIN32_FIND_DATAW_* lpFindFileData)
{
    return ::FindNextFileW(hFindFile, reinterpret_cast< ::_WIN32_FIND_DATAW* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ MoveFileExW(LPCWSTR_ lpExistingFileName, LPCWSTR_ lpNewFileName, DWORD_ dwFlags)
{
    return ::MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags);
}

BOOST_FORCEINLINE BOOL_ FindClose(HANDLE_ hFindFile)
{
    return ::FindClose(hFindFile);
}

BOOST_FORCEINLINE BOOL_ GetFileSizeEx(HANDLE_ hFile, LARGE_INTEGER_* lpFileSize)
{
    return ::GetFileSizeEx(hFile, reinterpret_cast< ::_LARGE_INTEGER* >(lpFileSize));
}

BOOST_FORCEINLINE BOOL_ SetFileValidData(HANDLE_ hFile, LONGLONG_ ValidDataLength)
{
    return ::SetFileValidData(hFile, ValidDataLength);
}

BOOST_FORCEINLINE BOOL_ SetEndOfFile(HANDLE_ hFile)
{
    return ::SetEndOfFile(hFile);
}

BOOST_FORCEINLINE BOOL_ LockFile(
    HANDLE_ hFile,
    DWORD_ dwFileOffsetLow,
    DWORD_ dwFileOffsetHigh,
    DWORD_ nNumberOfBytesToLockLow,
    DWORD_ nNumberOfBytesToLockHigh)
{
    return ::LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh);
}

BOOST_FORCEINLINE BOOL_ UnlockFile(
    HANDLE_ hFile,
    DWORD_ dwFileOffsetLow,
    DWORD_ dwFileOffsetHigh,
    DWORD_ nNumberOfBytesToUnlockLow,
    DWORD_ nNumberOfBytesToUnlockHigh)
{
    return ::UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh);
}

BOOST_FORCEINLINE BOOL_ LockFileEx(
    HANDLE_ hFile,
    DWORD_ dwFlags,
    DWORD_ dwReserved,
    DWORD_ nNumberOfBytesToLockLow,
    DWORD_ nNumberOfBytesToLockHigh,
    OVERLAPPED_* lpOverlapped)
{
    return ::LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, reinterpret_cast< ::_OVERLAPPED* >(lpOverlapped));
}

BOOST_FORCEINLINE BOOL_ UnlockFileEx(
    HANDLE_ hFile,
    DWORD_ dwReserved,
    DWORD_ nNumberOfBytesToUnlockLow,
    DWORD_ nNumberOfBytesToUnlockHigh,
    OVERLAPPED_* lpOverlapped)
{
    return ::UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, reinterpret_cast< ::_OVERLAPPED* >(lpOverlapped));
}

BOOST_FORCEINLINE BOOL_ WriteFile(
    HANDLE_ hFile,
    LPCVOID_ lpBuffer,
    DWORD_ nNumberOfBytesToWrite,
    LPDWORD_ lpNumberOfBytesWritten,
    OVERLAPPED_* lpOverlapped)
{
    return ::WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, reinterpret_cast< ::_OVERLAPPED* >(lpOverlapped));
};

#endif

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE HANDLE_ create_file(
    LPCSTR_ lpFileName,
    DWORD_ dwDesiredAccess,
    DWORD_ dwShareMode,
    SECURITY_ATTRIBUTES_* lpSecurityAttributes,
    DWORD_ dwCreationDisposition,
    DWORD_ dwFlagsAndAttributes,
    HANDLE_ hTemplateFile)
{
    return ::CreateFileA(
        lpFileName,
        dwDesiredAccess,
        dwShareMode,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpSecurityAttributes),
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);
}

BOOST_FORCEINLINE BOOL_ delete_file(LPCSTR_ lpFileName)
{
    return ::DeleteFileA(lpFileName);
}

BOOST_FORCEINLINE HANDLE_ find_first_file(LPCSTR_ lpFileName, WIN32_FIND_DATAA_* lpFindFileData)
{
    return ::FindFirstFileA(lpFileName, reinterpret_cast< ::_WIN32_FIND_DATAA* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ find_next_file(HANDLE_ hFindFile, WIN32_FIND_DATAA_* lpFindFileData)
{
    return ::FindNextFileA(hFindFile, reinterpret_cast< ::_WIN32_FIND_DATAA* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ move_file(LPCSTR_ lpExistingFileName, LPCSTR_ lpNewFileName, DWORD_ dwFlags)
{
    return ::MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags);
}
#endif

BOOST_FORCEINLINE HANDLE_ create_file(
    LPCWSTR_ lpFileName,
    DWORD_ dwDesiredAccess,
    DWORD_ dwShareMode,
    SECURITY_ATTRIBUTES_* lpSecurityAttributes,
    DWORD_ dwCreationDisposition,
    DWORD_ dwFlagsAndAttributes,
    HANDLE_ hTemplateFile)
{
    return ::CreateFileW(
        lpFileName,
        dwDesiredAccess,
        dwShareMode,
        reinterpret_cast< ::_SECURITY_ATTRIBUTES* >(lpSecurityAttributes),
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile);
}

BOOST_FORCEINLINE BOOL_ delete_file(LPCWSTR_ lpFileName)
{
    return ::DeleteFileW(lpFileName);
}

BOOST_FORCEINLINE HANDLE_ find_first_file(LPCWSTR_ lpFileName, WIN32_FIND_DATAW_* lpFindFileData)
{
    return ::FindFirstFileW(lpFileName, reinterpret_cast< ::_WIN32_FIND_DATAW* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ find_next_file(HANDLE_ hFindFile, WIN32_FIND_DATAW_* lpFindFileData)
{
    return ::FindNextFileW(hFindFile, reinterpret_cast< ::_WIN32_FIND_DATAW* >(lpFindFileData));
}

BOOST_FORCEINLINE BOOL_ move_file(LPCWSTR_ lpExistingFileName, LPCWSTR_ lpNewFileName, DWORD_ dwFlags)
{
    return ::MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags);
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_FILE_MANAGEMENT_HPP
