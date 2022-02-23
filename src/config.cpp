#include "../inc/config.h" 

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
std::ostream& operator<<(std::ostream& Str, ConfigFile const& v)
    {
        for (Process i : v.processes)
            Str << i ;
        return Str;
    }
std::ostream& operator<<(std::ostream& Str, Process const& v)
    {
        Str << v.name <<" "<< v.executable_path <<" ";
        for (CmdArgument i : v.cmd_arguments)
            Str << i <<" ";
        return Str;
    }
std::ostream& operator<<(std::ostream& Str, StdoutConfig const& v)
    {
        Str << v.file << " "<<v.mode << std::endl;
        return Str;
    }
std::ostream& operator<<(std::ostream& Str, CmdArgument const& v)
    {
        Str << v.option_name ;
        return Str;
    }
ConfigFile parseYAMLConfig(YAML::Node config)
{
    std::vector<Process> processes;
    ConfigFile config_file;
    for (std::size_t i = 0; i < config["processes"].size(); i++) {
        Process process;
        YAML::Node yaml_process = config["processes"][i];
        const std::string name = yaml_process["name"].as<std::string>();
        const std::string executable_path = yaml_process["executable-path"].as<std::string>();
        process.set_name(name);
        process.set_executable_path(executable_path);

        StdoutConfig stdout_config;
        const std::string stdout_file = yaml_process["stdout-config"]["file"].as<std::string>();
        const std::string stdout_mode = yaml_process["stdout-config"]["mode"].as<std::string>();
        stdout_config.set_file(stdout_file);
        stdout_config.set_mode(stdout_mode);
        process.set_stdout_config(stdout_config);

        std::vector<CmdArgument> cmd_arguments;
        for (std::size_t i = 0; i < yaml_process["cmd-arguments"].size(); i++) {
            CmdArgument cmd_argument;
            const std::string arg_option_name = yaml_process["cmd-arguments"][i]["option-name"].as<std::string>();
            cmd_argument.set_option_name(arg_option_name);
            cmd_arguments.push_back(cmd_argument);
        }
        process.set_cmd_arguments(cmd_arguments);
        processes.push_back(process);
    }
    config_file.set_processes(processes);
    return config_file;
}

const YAML::Node loadYaml()
{
     YAML::Node config = YAML::LoadFile("../lib/config.yaml");
     return config;
}