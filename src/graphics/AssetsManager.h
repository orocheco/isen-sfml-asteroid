//
// Created by orocheco on 15/03/2025.
//

#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Texture.hpp"


#include <map>

#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/Sound.hpp"

class AssetsManager {
private:
  std::map<std::string, std::shared_ptr<sf::Font>> _fonts;
  std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
  std::map<std::string, std::shared_ptr<sf::SoundBuffer>> _soundBuffers;
  std::map<std::string, std::shared_ptr<sf::Sound>> _sounds;
  std::map<std::string, std::shared_ptr<sf::Music>> _musics;

public:
  ~AssetsManager();
  /// returns Singleton
  static std::shared_ptr<AssetsManager> getInstance();

  /// load a font by filename
  void addFont(const std::string& name, const std::string& path);
  /// load a texture by filename
  void addTexture(const std::string& name, const std::string& path, bool smooth = true);
  /// load a sound  by filename
  void addSound(const std::string& name, const std::string& path);
  /// load a sound  by filename
  void addMusic(const std::string& name, const std::string& path);

  /// returns the font by id if it has been loaded
  std::shared_ptr<sf::Font> getFont(const std::string& name);
  /// returns the texture by id if it has been loaded
  std::shared_ptr<sf::Texture> getTexture(const std::string& name);
  /// returns the sound by id if
  std::shared_ptr<sf::Sound> getSound(const std::string& name);
  /// returns the music by id if it has been loaded
  std::shared_ptr<sf::Music> getMusic(const std::string& name);

private:
  AssetsManager();
};



#endif //ASSETSMANAGER_H
