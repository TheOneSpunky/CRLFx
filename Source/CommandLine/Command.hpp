/**
 *  CRLFx - Command.hpp
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

#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <span>
#include <optional>

namespace CRLFx::CommandLine {
  class Command {
  public:
    Command() noexcept;
    Command(const char& flag, std::string_view name, std::string_view description, std::optional<std::span<const std::string>> arguments = std::nullopt, std::optional<std::span<const Command>> dependencies = std::nullopt);
    Command(const Command& other) noexcept;
    Command(Command&& other) noexcept;
    virtual ~Command() noexcept = default;

    auto getFlag() const noexcept -> const char&;
    auto getName() const noexcept -> std::string_view;
    auto getDescription() const noexcept -> std::string_view;
    auto getArguments() const noexcept -> std::span<const std::string>;
    auto getDependencies() const noexcept -> std::span<const Command>;

    auto getFlagCopy() const noexcept -> char;
    auto getNameCopy() const noexcept -> std::string;
    auto getDescriptionCopy() const noexcept -> std::string;
    auto getArgumentsCopy() const noexcept -> std::vector<std::string>;
    auto getDependenciesCopy() const noexcept -> std::vector<Command>;

    auto setFlag(const char& flag) noexcept -> void;
    auto setName(std::string_view name) noexcept -> void;
    auto setDescription(std::string_view description) noexcept -> void;
    auto setArguments(std::span<const std::string> arguments) noexcept -> void;
    auto setDependencies(std::span<const Command> dependencies) noexcept -> void;

  private:
    char                     m_flag;
    std::string              m_name;
    std::string              m_description;
    std::vector<std::string> m_arguments;
    std::vector<Command>     m_dependencies;
  };
} // namespace CRLFx::CommandLine