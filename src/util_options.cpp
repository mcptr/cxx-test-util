#include <cxx-test-util/util_options.hpp>
#include <exception>
#include <iomanip>


namespace test {


Options::Options()
{
	po::options_description options("Generic");

	options.add_options()
		("help,h", "display this help")
		("verbose,v",
		 po::value<bool>()->implicit_value(true)->zero_tokens()->default_value(false),
		 "verbose run")
		("debug,D",
		 po::value<bool>()->implicit_value(true)->zero_tokens()->default_value(false),
		 "debug run")
		("no-cleanup,N",
		 po::value<bool>()->implicit_value(true)->zero_tokens()->default_value(false),
		 "do not clean logs/tmp")
#if defined(EASYLOGGINGPP_H)
		("logfile,l",
		 po::value<std::string>()->default_value(""),
		 "logfile ")
#endif
		;

	all_.add(options);
}

void Options::dump_variables_map() const
{
	for (const auto& it : vm_) {
		std::cout << ": "  << std::setw(48) << std::left << it.first;
		std::cout.width(0);
		auto& raw = it.second.value();
		if (auto v = boost::any_cast<int>(&raw)) {
			std::cout << *v;
		}
		else if (auto v = boost::any_cast<std::string>(&raw)) {
			std::cout << *v;
		}
		else if (auto v = boost::any_cast<bool>(&raw)) {
			std::cout << *v;
		}

		std::cout << std::endl;
	}
}

bool Options::parse(int argc, const char* const* argv)
{
	using namespace std;

	try {
		set_custom_options();
		po::store(po::command_line_parser(argc, argv).options(all_).run(), vm_);
		po::notify(vm_);
	}
	catch(exception& e) {
		cerr << "error: " << e.what() << "\n";
		return false;
	}
	return true;
}

void Options::add(const po::options_description& options)
{
	all_.add(options);
}

void Options::set_custom_options()
{
	// empty. Override to add options to all_.
}

bool Options::has_help() const
{
	return vm_.count("help");
}

void Options::display_help() const
{
	std::cout << all_ << std::endl;
}

bool Options::is_verbose() const
{
	return get<bool>("verbose");
}

bool Options::is_debug() const
{
	return get<bool>("debug");
}

} // test
