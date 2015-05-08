#include <iostream>

#include <wif_core/wif_core.hpp>
#include <wif_algo/wif_algo.hpp>
#include <wif_viz/wif_viz.hpp>
#include <fstream>

int main()
{

	system("cd /home/uauser/Shared/coord_seligFmt.tar/coord_seligFmt");
	system("ls > files.txt");
	std::ifstream filelist("/home/uauser/Shared/coord_seligFmt.tar/coord_seligFmt/files.txt");

	while(!filelist.eof())
	{
		std::string filename1;
		filelist >> filename1;
		std::cout << filename1 << std::endl;
		filename1 = "/home/uauser/Shared/coord_seligFmt.tar/coord_seligFmt/" + filename1 ;
		std::cout << filename1 << std::endl;
		wif_core::airfoil_c airfoil1(filename1);
		std::cout << airfoil1;
		std::cout << airfoil1.close_merge();
		std::cout << airfoil1.close_intersect();
		break;
		//std::cout << airfoil1.get_circle_projection(9, wif_core::vector_2d_c(0.5, 0.0) , 0.5);
	}

	/* Deze code geeft een gigantische memory leak. Het crasht mijn vb... Fixt dit aub
	Gebruik ook geen absolute paden...
	kan niet anders, want een relatief pad kan elleen verterekken in de build/bin directory.

	std::string filename1 = "/home/uauser/eindopdracht/will-it-fly/wif_core/airfoils/lednicer.dat";
	wif_core::airfoil_c airfoil1(filename1);
	std::cout << airfoil1;
	std::cout << airfoil1.get_circle_projection(9, wif_core::vector_2d_c(0.5, 0.0) , 0.5);
	std::string filename2 = "/home/uauser/eindopdracht/will-it-fly/wif_core/airfoils/selig.dat";
	wif_core::airfoil_c airfoil2(filename2);
	std::cout << airfoil2;
	std::cout << airfoil2.get_circle_projection(9, wif_core::vector_2d_c(0.5, 0.0), 0.5);

	std::vector<wif_core::vector_2d_c> test;
	test.push_back(wif_core::vector_2d_c(1.0, 0.02));
	test.push_back(wif_core::vector_2d_c(0.0, 0.02));
	wif_core::airfoil_c airfoil(test, "flat");
	std::cout << airfoil;
	std::cout << airfoil.get_circle_projection(10, wif_core::vector_2d_c(0.5, 0.0), 0.5);
	wif_core::airfoil_c airfoil3(wif_core::vector_2d_c(0.5, 0.0), 0.5, 8);
	std::cout << airfoil3;
	*/

	return 0; // Komaan mensen? return code vergeten????
}
