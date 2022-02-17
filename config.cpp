#include "config.h"

const std::string& CmdArgument::get_option_name() const
{
    return option_name;
}
void CmdArgument::set_option_name(const std::string& value)
{
    this->option_name = value;
}

const std::string& StdoutConfig::get_file() const
{
    return file;
}
void StdoutConfig::set_file(const std::string& value)
{
    this->file = value;
}
const std::string& StdoutConfig::get_mode() const
{
    return mode;
}
void StdoutConfig::set_mode(const std::string& value)
{
    this->mode = value;
}

const std::string& Process::get_name() const
{
    return name;
}
void Process::set_name(const std::string& value)
{
    this->name = value;
}
const std::string& Process::get_executable_path() const
{
    return executable_path;
}
void Process::set_executable_path(const std::string& value)
{
    this->executable_path = value;
}
const StdoutConfig& Process::get_stdout_config() const
{
    return stdout_config;
}
void Process::set_stdout_config(const StdoutConfig& value)
{
    this->stdout_config = value;
}
const std::vector<CmdArgument>& Process::get_cmd_arguments() const
{
    return cmd_arguments;
}
void Process::set_cmd_arguments(const std::vector<CmdArgument>& value)
{
    this->cmd_arguments = value;
}

const std::vector<Process>& ConfigFile::get_processes() const
{
    return processes;
}

void ConfigFile::set_processes(const std::vector<Process>& value)
{
    this->processes = value;
}
