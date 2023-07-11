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

namespace CRLFx::CommandLine {
  class Command {
  public:
    Command() noexcept;
    Command(const char& flag, std::string_view name, std::string_view description, std::span<const std::string> arguments = {}, std::span<const Command> dependencies = {}) noexcept;
    Command(const Command& other) noexcept;
    Command(Command&& other) noexcept;
    virtual ~Command() noexcept = default;

  private:
    char                     m_flag;
    std::string              m_name;
    std::string              m_description;
    std::vector<std::string> m_arguments;
    std::vector<Command>     m_dependencies;
  };
} // namespace CRLFx::CommandLine