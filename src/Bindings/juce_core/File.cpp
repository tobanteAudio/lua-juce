#include "File.hpp"

#include <juce_core/juce_core.h>

auto juce_File(sol::table& state) -> void
{
    // clang-format off
    auto file = state.new_usertype<juce::File>("File",
        sol::constructors<juce::File(), juce::File(juce::String const&)>()
    );
    file.set_function("findChildFiles", sol::overload(
            // Array<File> findChildFiles(int whatToLookFor, bool searchRecursively, const String &wildCardPattern="*") const
            [](juce::File const* self, int what, bool recursive) { return self->findChildFiles(what, recursive); },
            static_cast<juce::Array<juce::File> (juce::File::*)(int, bool, juce::String const&) const>(&juce::File::findChildFiles),
            
            // int findChildFiles(Array<File> &results, int whatToLookFor, bool searchRecursively, const String &wildCardPattern="*") const
            [](juce::File const* self, juce::Array<juce::File>& results, int what, bool recursive) { return self->findChildFiles(results, what, recursive); },
            static_cast<int (juce::File::*)(juce::Array<juce::File>&, int, bool, juce::String const&) const>(&juce::File::findChildFiles)
        )
    );
    // clang-format on

    file["exists"]                        = &juce::File::exists;
    file["existsAsFile"]                  = &juce::File::existsAsFile;
    file["isDirectory"]                   = &juce::File::isDirectory;
    file["isRoot"]                        = &juce::File::isRoot;
    file["getSize"]                       = &juce::File::getSize;
    file["descriptionOfSizeInBytes"]      = &juce::File::descriptionOfSizeInBytes;
    file["getFullPathName"]               = &juce::File::getFullPathName;
    file["getFileName"]                   = &juce::File::getFileName;
    file["getRelativePathFrom"]           = &juce::File::getRelativePathFrom;
    file["getFileExtension"]              = &juce::File::getFileExtension;
    file["hasFileExtension"]              = &juce::File::hasFileExtension;
    file["withFileExtension"]             = &juce::File::withFileExtension;
    file["getFileNameWithoutExtension"]   = &juce::File::getFileNameWithoutExtension;
    file["hashCode"]                      = &juce::File::hashCode;
    file["hashCode64"]                    = &juce::File::hashCode64;
    file["getChildFile"]                  = &juce::File::getChildFile;
    file["getSiblingFile"]                = &juce::File::getSiblingFile;
    file["getParentDirectory"]            = &juce::File::getParentDirectory;
    file["isAChildOf"]                    = &juce::File::isAChildOf;
    file["getNonexistentChildFile"]       = &juce::File::getNonexistentChildFile;
    file["getNonexistentSibling"]         = &juce::File::getNonexistentSibling;
    file["hasWriteAccess"]                = &juce::File::hasWriteAccess;
    file["setReadOnly"]                   = &juce::File::setReadOnly;
    file["setExecutePermission"]          = &juce::File::setExecutePermission;
    file["isHidden"]                      = &juce::File::isHidden;
    file["getFileIdentifier"]             = &juce::File::getFileIdentifier;
    file["getLastModificationTime"]       = &juce::File::getLastModificationTime;
    file["getLastAccessTime"]             = &juce::File::getLastAccessTime;
    file["getCreationTime"]               = &juce::File::getCreationTime;
    file["setLastModificationTime"]       = &juce::File::setLastModificationTime;
    file["setLastAccessTime"]             = &juce::File::setLastAccessTime;
    file["setCreationTime"]               = &juce::File::setCreationTime;
    file["getVersion"]                    = &juce::File::getVersion;
    file["create"]                        = &juce::File::create;
    file["createDirectory"]               = &juce::File::createDirectory;
    file["deleteFile"]                    = &juce::File::deleteFile;
    file["deleteRecursively"]             = &juce::File::deleteRecursively;
    file["moveToTrash"]                   = &juce::File::moveToTrash;
    file["moveFileTo"]                    = &juce::File::moveFileTo;
    file["copyFileTo"]                    = &juce::File::copyFileTo;
    file["replaceFileIn"]                 = &juce::File::replaceFileIn;
    file["copyDirectoryTo"]               = &juce::File::copyDirectoryTo;
    file["getNumberOfChildFiles"]         = &juce::File::getNumberOfChildFiles;
    file["containsSubDirectories"]        = &juce::File::containsSubDirectories;
    file["createInputStream"]             = &juce::File::createInputStream;
    file["createOutputStream"]            = &juce::File::createOutputStream;
    file["loadFileAsData"]                = &juce::File::loadFileAsData;
    file["loadFileAsString"]              = &juce::File::loadFileAsString;
    file["readLines"]                     = &juce::File::readLines;
    file["appendData"]                    = &juce::File::appendData;
    file["replaceWithData"]               = &juce::File::replaceWithData;
    file["appendText"]                    = &juce::File::appendText;
    file["replaceWithText"]               = &juce::File::replaceWithText;
    file["hasIdenticalContentTo"]         = &juce::File::hasIdenticalContentTo;
    file["findFileSystemRoots"]           = &juce::File::findFileSystemRoots;
    file["getVolumeLabel"]                = &juce::File::getVolumeLabel;
    file["getVolumeSerialNumber"]         = &juce::File::getVolumeSerialNumber;
    file["getBytesFreeOnVolume"]          = &juce::File::getBytesFreeOnVolume;
    file["getVolumeTotalSize"]            = &juce::File::getVolumeTotalSize;
    file["isOnCDRomDrive"]                = &juce::File::isOnCDRomDrive;
    file["isOnHardDisk"]                  = &juce::File::isOnHardDisk;
    file["isOnRemovableDrive"]            = &juce::File::isOnRemovableDrive;
    file["startAsProcess"]                = &juce::File::startAsProcess;
    file["revealToUser"]                  = &juce::File::revealToUser;
    file["getSpecialLocation"]            = &juce::File::getSpecialLocation;
    file["createTempFile"]                = &juce::File::createTempFile;
    file["getCurrentWorkingDirectory"]    = &juce::File::getCurrentWorkingDirectory;
    file["setAsCurrentWorkingDirectory"]  = &juce::File::setAsCurrentWorkingDirectory;
    file["getSeparatorChar"]              = &juce::File::getSeparatorChar;
    file["getSeparatorString"]            = &juce::File::getSeparatorString;
    file["createLegalFileName"]           = &juce::File::createLegalFileName;
    file["createLegalPathName"]           = &juce::File::createLegalPathName;
    file["areFileNamesCaseSensitive"]     = &juce::File::areFileNamesCaseSensitive;
    file["isAbsolutePath"]                = &juce::File::isAbsolutePath;
    file["createFileWithoutCheckingPath"] = &juce::File::createFileWithoutCheckingPath;
    file["addTrailingSeparator"]          = &juce::File::addTrailingSeparator;
    file["isSymbolicLink"]                = &juce::File::isSymbolicLink;
    file["getLinkedTarget"]               = &juce::File::getLinkedTarget;
    file["getNativeLinkedTarget"]         = &juce::File::getNativeLinkedTarget;

#if JUCE_WINDOWS
    file["createShortcut"] = &juce::File::createShortcut;
    file["isShortcut"]     = &juce::File::isShortcut;
#endif

#if JUCE_MAC
    file["getMacOSType"] = &juce::File::getMacOSType;
    file["isBundle"]     = &juce::File::isBundle;
    file["addToDock"]    = &juce::File::addToDock;
#endif

    // TODO(tobi): createSymbolicLink
}