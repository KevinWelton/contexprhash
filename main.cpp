#include <stdlib.h>
#include <string>

#include "sha256_constexpr/sha256.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    constexpr std::string test_value_short = "abcdefgh";

    constexpr std::string testval_short_sha256 = sha256(test_value_short);

    printf("testval_short_sha256\nInitialMessage=%s\nHashedValue=%s\n\n", test_value_short.c_str(), testval_short_sha256.c_str());

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.