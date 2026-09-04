#include "OOPUtils.h"


// receive a string, break it apart using the delimiter as a 
// breakpoint, return a vector with the parts
std::vector<std::string> OOPUtils::split(const std::string& source, const std::string& delimiter) {
	std::vector<std::string> result;

	int start = 0;
	int end;

	// what we need to do is search for the indexes
	end = source.find(delimiter);

	// optimize this in a couple of years!
	while (end != std::string::npos) {
		
		// get slice
		std::string part = source.substr(start, end - start);

		// save slice 
		result.push_back(part);

		// we need a new start!
		start = end + delimiter.length();

		// search for new end position
		end = source.find(delimiter, start);
	}
	
	// add the last part
	result.push_back(source.substr(start));
	return result;
}