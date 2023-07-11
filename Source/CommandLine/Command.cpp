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

  Command::Command(const char& flag, std::string_view name, std::string_view description, std::span<const std::string> arguments, std::span<const Command> dependencies) noexcept
    : m_flag         { flag },
      m_name         { name },
      m_description  { description },
      m_arguments    { arguments.begin(), arguments.end() },
      m_dependencies { dependencies.begin(), dependencies.end() } {}

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
} // namespace CRLFx::CommandLine
