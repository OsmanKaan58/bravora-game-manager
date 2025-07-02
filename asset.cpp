#include "asset.h"

Asset::Asset()
{
}

Asset::Asset(int id, std::string name, std::string filePath, AssetType type,
             std::string description, bool synced)
    : id(id), name(name), filePath(filePath), type(type),
      description(description), synced(synced)
{
}

int Asset::getId() const
{
    return id;
}
std::string Asset::getName() const
{
    return name;
}
std::string Asset::getDescription() const
{
    return description;
}
std::string Asset::getFilePath() const
{
    return filePath;
}
AssetType Asset::getType() const
{
    return type;
}
bool Asset::isSynced() const
{
    return synced;
}
void Asset::setId(int id)
{
    this->id = id;
}
void Asset::setName(const std::string& name)
{
    this->name = name;
}
void Asset::setDescription(const std::string& description)
{
    this->description = description;
}
void Asset::setFilePath(const std::string& filePath)
{
    this->filePath = filePath;
}
void Asset::setType(AssetType type)
{
    this->type = type;
}
void Asset::setSynced(bool synced)
{
    this->synced = synced;
}
