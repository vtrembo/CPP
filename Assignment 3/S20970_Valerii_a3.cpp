#include <iostream>
uint64_t encode(int caller, int caller_zone,
	int callee, int callee_zone,
	int duration, int tariff) {
	uint64_t collector = 0;
	collector += caller;
	collector <<= 7;
	collector += caller_zone;
	collector <<= 17;
	collector += callee;
	collector <<= 7;
	collector += callee_zone;
	collector <<= 13;
	collector += duration;
	collector <<= 3;
	collector += tariff;
	return collector;
}
void info(uint64_t res) {
	int tariff = res & 0b111;
	res = res >> 3;
	int duration = res & 0x1FFF;
	res = res >> 13;
	int callee_zone = res & 0b1111111;
	res = res >> 7;
	int callee = res & 0x1FFFF;
	res = res >> 17;
	int caller_zone = res & 0b1111111;
	res = res >> 7;
	int caller = res & 0x1FFFF;
	std::cout << "Caller: " << caller << "\n";
	std::cout << "Caller_zone: " << caller_zone << "\n";
	std::cout << "Callee: " << callee << "\n";
	std::cout << "Callee_zone: " << callee_zone << "\n";
	std::cout << "Duration: " << duration << "\n";
	std::cout << "Tariff: " << tariff << "\n";
}
int main() {
	info(encode(130999, 101, 7777, 99, 7000, 6));
}