#ifndef ENGINE_UTIL_STRINGUTIL_H
#define ENGINE_UTIL_STRINGUTIL_H

namespace engine {
namespace util {

	//TODO: Make this more generic (2013-02-14)

	std::vector<String> explode(String const & input,char delim){
		std::vector<String> result;
		std::istringstream iss(input);

		for(String token; std::getline(iss,token,delim);){
			if(!token.empty()){
				result.push_back(boost::move(token));
			}
		}
		return result;
	}

}
}

#endif
