#ifndef CONFIG_H
#define CONFIG_H
#include <vector>
#include <string>

class CmdArgument {
public:
    CmdArgument(){};
    ~CmdArgument(){};

private:
    std::string option_name;

public:
    const std::string& get_option_name() const;
    void set_option_name(const std::string& value);
    friend std::ostream& operator<<(std::ostream& Str, CmdArgument const& v)
    {
        Str << "cmd_argument{" << std::endl
            << v.option_name << "}" << std::endl;
        return Str;
    }
};

class StdoutConfig {
public:
    StdoutConfig(){};
    ~StdoutConfig(){};

private:
    std::string file;
    std::string mode;

public:
    const std::string& get_file() const;
    void set_file(const std::string& value);
    const std::string& get_mode() const;
    void set_mode(const std::string& value);
    friend std::ostream& operator<<(std::ostream& Str, StdoutConfig const& v)
    {
        Str << "stdout_config:{" << std::endl
            << v.file << std::endl
            << v.mode << "}" << std::endl;
        return Str;
    }
};

class Process {
public:
    Process(){};
    ~Process(){};

private:
    std::string name;
    std::string executable_path;
    StdoutConfig stdout_config;
    std::vector<CmdArgument> cmd_arguments;

public:
    const std::string& get_name() const;
    void set_name(const std::string& value);
    const std::string& get_executable_path() const;
    void set_executable_path(const std::string& value);
    const StdoutConfig& get_stdout_config() const;
    void set_stdout_config(const StdoutConfig& value);
    const std::vector<CmdArgument>& get_cmd_arguments() const;
    void set_cmd_arguments(const std::vector<CmdArgument>& value);
    friend std::ostream& operator<<(std::ostream& Str, Process const& v)
    {
        Str << "Process{" << std::endl
            << v.name << std::endl
            << v.executable_path << std::endl
            << v.stdout_config << std::endl;
        for (CmdArgument i : v.cmd_arguments)
            Str << i << std::endl;
        Str << "}" << std::endl;
        return Str;
    }
};

class ConfigFile {
public:
    ConfigFile(){};
    ~ConfigFile(){};

private:
    std::vector<Process> processes;

public:
    const std::vector<Process>& get_processes() const;
    void set_processes(const std::vector<Process>& value);
    friend std::ostream& operator<<(std::ostream& Str, ConfigFile const& v)
    {
        Str << "ConfigFile{" << std::endl;
        for (Process i : v.processes)
            Str << i << std::endl;
        Str << "}" << std::endl;
        return Str;
    }
};
#endif