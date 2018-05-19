/*
 * Copyright (c) 2018 Guo Xiang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include <EasyCpp.hpp>
#include <IIo.hpp>

#include <DynamicLibrary.hpp>

namespace Platform {

IDirentPtr CreateDirent(const CConstStringPtr &path);

IFilePtr CreateFile(const CConstStringPtr &path,
					IFile::FilePerm perm = IFile::RW);

CConstStringPtr GetDir(void);
void ChangeDir(const CConstStringPtr &path);

DEFINE_CLASS(DynamicLibrary);
inline decltype(auto) CreateDynamicLib(const CConstStringPtr &path)
{
	return CDynamicLibrary::Create(path);
}

}

using namespace Platform;

#endif /* __SOCKET_HPP__ */

