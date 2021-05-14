#ifndef CALM_BASE_CONFIGFILEREADER_H_
#define CALM_BASE_CONFIGFILEREADER_H_

#include <uncopyable.h>

#include <map>
#include <string>
namespace calm
{
	class ConfigFileReader :calm::uncopyable
	{
	public:
		ConfigFileReader(const char* filename);
		~ConfigFileReader();

		char* GetConfigName(const char* name);
		int SetConfigValue(const char* name, const char*  value);
	private:
		void _LoadFile(const char* filename);
		int _WriteFile(const char*filename = NULL);
		void _ParseLine(char* line);
		char* _TrimSpace(char* name);

		bool m_load_ok;
		std::map<std::string, std::string> m_config_map;
		std::string m_config_file;
	};//end class ConfigFileReader
} //end namespace calm

#endif // !CALM_BASE_CONFIGFILEREADER_H_
