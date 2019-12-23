#pragma once

#ifndef CXX_TEST_UTIL_UTIL_OPTIONS_HPP
#define CXX_TEST_UTIL_UTIL_OPTIONS_HPP

#include <cxx-test-util/stdcpp.hpp>
#include <boost/program_options.hpp>


namespace test {


namespace po = boost::program_options;

class Options
{
public:
	Options();
	virtual ~Options() = default;

	template <class T>
	const T get(const std::string& k, const T& default_value = T()) const
	{
		if(!vm_.count(k)) {
			return default_value;
		}

		try {
			return vm_[k].as<T>();
		}
		catch(const boost::bad_any_cast& e) {
			std::cerr << "ERROR: Options::get(): " << k << std::endl;
			throw e;
		}
	}

	void dump_variables_map() const;

	bool parse(int argc, const char* const* argv);
	bool has_help() const;
	void display_help() const;

	bool is_verbose() const;
	bool is_debug() const;

	void add(const po::options_description& options);
protected:
	virtual void set_custom_options();

	po::variables_map vm_;
	po::options_description all_;
};


} // test

#endif
