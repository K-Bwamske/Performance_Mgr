#include <iostream>
#include <algorithm>
#include <filesystem>
#include "List.h"
using namespace std;

void list() {
	namespace sys = std::tr2::sys;
	sys::path p(".\\data\\"); // 列挙の起点
	std::for_each(sys::recursive_directory_iterator(p), sys::recursive_directory_iterator(),
		[](const sys::path& p) {
		if (sys::is_regular_file(p)) { // ファイルなら...

			//出力の方法を変えてくださいね
			cout << p.parent_path() << "\\" << p.filename() << endl;
		}
	});
}