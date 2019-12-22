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
	Options() = default;
	virtual ~Options() = default;

	template <class T>
	const T get(const std::string& k) const
	{
		try {
			return vm_[k].as<T>();
		}
		catch(boost::bad_any_cast& e) {
			std::cerr << "ERROR: Options::get(): " << k << std::endl;
			throw e;
		}
	}

	void dump_variables_map() const;

	bool parse(int argc, char** argv);
	bool has_help() const;
	void display_help() const;

	bool is_verbose() const;
	bool is_debug() const;

protected:
	po::variables_map vm_;
	po::options_description all_;

};


} // test

#endif
