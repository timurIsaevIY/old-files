#include <iostream>
using namespace std;
class Download {
public:
	virtual string downloading() = 0;
};

class DownloadPicture : public Download{

	string downloading() override {
		return "picture";
	}
};
class DownloadText : public Download {

	string downloading() override {
		return "text";
	}
};

class Interface {
protected:
	Download* download;
public:
	Interface(Download* download) { this->download = download; }
	
	virtual string Operation() const {
		return "Download: " + download->downloading();
		
	}
};
void PrintResult(const Interface& interface) {
	cout << interface.Operation() << endl;
}
int main() {
	Download* download = new DownloadPicture;
	Interface* interface = new Interface(download);
	PrintResult(*interface);

	download = new DownloadText;
	interface = new Interface(download);
	PrintResult(*interface);
	delete download;
	delete interface;
}