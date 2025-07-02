#ifndef ASSET_H
#define ASSET_H

#include <string>

enum class AssetType {
    Image,
    Document,
    Model,
    Script,
    Unknown
};

class Asset
{
public:
    Asset();
    Asset(int id, std::string name, std::string filePath, AssetType type,
          std::string description = "", bool synced = false);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    std::string getFilePath() const;
    AssetType getType() const;
    bool isSynced() const;

    // Setters
    void setId(int id);
    void setName(const std::string &name);
    void setDescription(const std::string &description);
    void setFilePath(const std::string &filePath);
    void setType(AssetType type);
    void setSynced(bool synced);

private:
    int id;
    std::string name;
    std::string description;
    std::string filePath;
    AssetType type;
    bool synced;
};


#endif // ASSET_H
