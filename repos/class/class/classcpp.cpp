#include <iostream>
using namespace std;

class DefaultBoots {
public:
	string name;
	string brand;
	string color;
	void info() {
		cout << name << " " << brand << " " << color << endl;
	}
};

class DefaultBootsBuilder {
public:
	DefaultBoots boot;
	void build_name(string name) {
		boot.name = name;
	}
	void build_brand(string brand) {
		boot.brand = brand;
	}
	void build_color(string color) {
		boot.color = color;
	}
	DefaultBoots ret() {
		return boot;
	}
};

class Director {
public:
	DefaultBoots OrderToCreateBoot(DefaultBootsBuilder builder, string name, string brand, string color) {
		builder.build_name(name);
		builder.build_brand(brand);
		builder.build_color(color);
		return (builder.ret());
	}
};
int main() {
	Director dir;
	DefaultBootsBuilder builder;
	DefaultBoots boot = dir.OrderToCreateBoot(builder,"boots", "abibas", "pink");
	boot.info();

}