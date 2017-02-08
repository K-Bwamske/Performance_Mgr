#include <iostream>
#include <algorithm>
#include <filesystem>
#include "List.h"
using namespace std;

void list() {
	namespace sys = std::tr2::sys;
	sys::path p(".\\data\\"); // �񋓂̋N�_
	std::for_each(sys::recursive_directory_iterator(p), sys::recursive_directory_iterator(),
		[](const sys::path& p) {
		if (sys::is_regular_file(p)) { // �t�@�C���Ȃ�...

			//�o�͂̕��@��ς��Ă���������
			cout << p.parent_path() << "\\" << p.filename() << endl;
		}
	});
}