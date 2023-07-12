/**
 *  CRLFx - Command.cpp
 *
 *  CRLFx is a program that converts plain-text files between the Unix/Linux, Windows, and Macintosh text file formats.
 *  Copyright (C) 2023 Kyle Swecker
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Command.hpp"

namespace CRLFx::CommandLine {
  Command::Command() noexcept
    : m_flag         { '\0' },
      m_name         { "" },
      m_description  { "" },
      m_arguments    {},
      m_dependencies {} {}

  Command::Command(const char& flag, std::string_view name, std::string_view description, std::optional<std::span<const std::string>> arguments, std::optional<std::span<const Command>> dependencies)
    : m_flag         { flag },
      m_name         { name },
      m_description  { description },
      m_arguments    { arguments ? std::vector<std::string>{arguments->begin(), arguments->end()} : std::vector<std::string>{} },
      m_dependencies { dependencies ? std::vector<Command>{dependencies->begin(), dependencies->end()} : std::vector<Command>{} } {}

  Command::Command(const Command& other) noexcept
    : m_flag         { other.m_flag },
      m_name         { other.m_name },
      m_description  { other.m_description },
      m_arguments    { other.m_arguments },
      m_dependencies { other.m_dependencies } {}

  Command::Command(Command&& other) noexcept
    : m_flag         { std::move(other.m_flag) },
      m_name         { std::move(other.m_name) },
      m_description  { std::move(other.m_description) },
      m_arguments    { std::move(other.m_arguments) },
      m_dependencies { std::move(other.m_dependencies) } {}

  auto Command::getFlag() const noexcept -> const char& {
    return m_flag;
  }

  auto Command::getName() const noexcept -> std::string_view {
    return m_name;
  }

  auto Command::getDescription() const noexcept -> std::string_view {
    return m_description;
  }

  auto Command::getArguments() const noexcept -> std::span<const std::string> {
    return m_arguments;
  }

  auto Command::getDependencies() const noexcept -> std::span<const Command> {
    return m_dependencies;
  }

  auto Command::getFlagCopy() const noexcept -> char {
    return m_flag;
  }

  auto Command::getNameCopy() const noexcept -> std::string {
    return m_name;
  }

  auto Command::getDescriptionCopy() const noexcept -> std::string {
    return m_description;
  }

  auto Command::getArgumentsCopy() const noexcept -> std::vector<std::string> {
    return m_arguments;
  }

  auto Command::getDependenciesCopy() const noexcept -> std::vector<Command> {
    return m_dependencies;
  }

  auto Command::setDescription(std::string_view description) noexcept -> void {
    m_description = description;
  }

  auto Command::setArguments(std::span<const std::string> arguments) noexcept -> void {
    m_arguments = std::vector<std::string>{arguments.begin(), arguments.end()};
  }

  auto Command::setDependencies(std::span<const Command> dependencies) noexcept -> void {
    m_dependencies = std::vector<Command>{dependencies.begin(), dependencies.end()};
  }
} // namespace CRLFx::CommandLine
