/******************************************
 *  Autor       :    PCMA-SOFT
 *  Description :    Testing
 *  Project     :    utiles
 *  Date        :    25/8/2025 12:38
 *  Version     :    1.0.0.
 *******************************************/

#include <iostream>
#include "utiles.hpp"
#include "logger.hpp"
using namespace ut;
// MAIN FUNCTION
int main(int argc, char *argv[])
{
	// INITIALIZE
	init();
	std::cout << "Setting console output UTF-8 for any characters types e.g. (¡Español!, Français, 日本語, 🤣😂😄🙂😎👀⚽✅)" << std::endl;

	// SET CONSOLE TITLE
	set_title("App test");

	color_red();
	std::cout << "Color:  red" << std::endl;

	color_white();
	std::cout << "Color:  white" << std::endl;

	color_yellow();
	std::cout << "Color:  yellow" << std::endl;

	color_green();
	std::cout << "Color:  green" << std::endl;

	color_magenta();
	std::cout << "Color:  magenta" << std::endl;

	color_grey();
	std::cout << "Color:  grey" << std::endl;

	color_blue();
	std::cout << "Color:  blue" << std::endl;

	color_reset();
	std::cout << "Reset all colors!" << std::endl;

	// HIDE CURSOR

	// LOGS

	// TIMESTAMP (TODAY,FILETIME,ETC)

	// TEST UTF-8 OUTPUT
	std::cout << std::endl;
	std::cout << "UTF-8 test with multiple languages:" << std::endl;
	std::cout << "Hola mundo en español" << std::endl;
	std::cout << "Hello world in English" << std::endl;
	std::cout << "Bonjour le monde en français" << std::endl;
	std::cout << "Hallo Welt auf Deutsch" << std::endl;
	std::cout << "Ciao mondo in italiano" << std::endl;
	std::cout << "こんにちは世界 in Japanese" << std::endl;
	std::cout << "안녕하세요 세계 in Korean" << std::endl;
	std::cout << "你好，世界 in Chinese" << std::endl;
	std::cout << "Olá mundo em português" << std::endl;
	std::cout << "Привет мир на русском" << std::endl;
	std::cout << "مرحبا بالعالم in Arabic" << std::endl;
	std::cout << "שלום עולם in Hebrew" << std::endl;
	std::cout << "नमस्ते दुनिया in Hindi" << std::endl;
	std::cout << "Hej världen på svenska" << std::endl;
	std::cout << "Hej verden på dansk" << std::endl;
	std::cout << "Hei maailma suomeksi" << std::endl;
	std::cout << "Salve lume in Latin" << std::endl;
	std::cout << "Witaj świecie po polsku" << std::endl;
	std::cout << "Sawubona mhlaba in Zulu" << std::endl;
	std::cout << "Sannu duniya in Hausa" << std::endl;
	std::cout << "Selam dünya in Turkish" << std::endl;
	std::cout << "Halo dunia dalam Bahasa Indonesia" << std::endl;
	std::cout << "Chào thế giới in Vietnamese" << std::endl;
	std::cout << "Hej världen på svenska" << std::endl;
	std::cout << "Kamusta mundo in Filipino" << std::endl;
	std::cout << "Tere maailm in Estonian" << std::endl;
	std::cout << "Ahoj světe in Czech" << std::endl;
	std::cout << "Szia világ in Hungarian" << std::endl;
	std::cout << "Merhaba dünya in Turkish" << std::endl;
	std::cout << "Cześć świecie in Polish" << std::endl;
	std::cout << "Saluton mondo in Esperanto" << std::endl;
	std::cout << "Hallo wereld in Dutch" << std::endl;
	std::cout << "Hei maailma in Finnish" << std::endl;
	std::cout << "Hej världen in Swedish" << std::endl;
	std::cout << "Salut lume in Romanian" << std::endl;
	std::cout << "Pozdravljen svet in Slovenian" << std::endl;

	// FINALIZE
	std::cout << std::endl;
	color_white();
	std::cout << "All tests has passing..." << std::endl;

	return EXIT_SUCCESS;
}
