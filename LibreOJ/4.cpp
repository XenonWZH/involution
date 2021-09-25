// #4. Quine
// WzhDnwzWzh

#include <cstdio>

constexpr char str[] = R"(// #4. Quine
// WzhDnwzWzh

#include <cstdio>

constexpr char str[] = R"(%s%c";

int main() {
	printf(str, str, ')');
	return 0;
})";

int main() {
	printf(str, str, ')');
	return 0;
}