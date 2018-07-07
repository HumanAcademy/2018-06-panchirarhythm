#include "XLibrary11.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
using namespace XLibrary11;
std::mt19937 mt;

enum Mode
{
	Title,
	Tutorial,
	Stage1,
	Game,
	Gazou,
	Gameclear,
	Gameover,
	Stage2,
	Game2,
	Gazou2,
	Gameclear2,
	Gameover2
};

Float3 Position()
{
	std::uniform_real_distribution<float> range(-30000.0f, 0.0f);
	return Float3(
		-App::GetWindowSize().x / 2 + range(mt),
		-125.0f,
		0.0f
	);
}
Float3 Position2()
{
	std::uniform_real_distribution<float> range(0.0f, 30000.0f);
	return Float3(
		App::GetWindowSize().x / 2 + range(mt),
		-125.0f,
		0.0f
	);
}

int MAIN()
{
	Mode mode = Title;

	Camera camera;

	std::random_device device;
	mt.seed(device());

	int count = 0;

	int girlcount = false;
	Sprite girl(L"girl.png");
	girl.position = Float3(-70.0f, -80.0f, 0.0f);
	girl.scale = 0.35f;
	bool girlFlag = false;

	Sprite girl2(L"girl2.png");
	girl2.position = Float3(-65.0f, -85.0f, 0.0f);
	girl2.scale = 0.3f;

	int girl3count = false;
	Sprite girl3(L"girl3.png");
	girl3.position = Float3(-105.0f, -117.0f, 0.0f);
	girl3.scale = 0.225f;
	bool girl3Flag = false;

	Sprite girl4(L"girl4.png");
	girl4.position = Float3(-125.0f, -112.0f, 0.0f);
	girl4.scale = 0.225f;

	int tomocount = 0;
	Sprite tomodati(L"friend.png");
	tomodati.position = Float3(40.0f, -80.0f, 0.0f);
	tomodati.scale = 0.35f;
	bool tomoFlag = false;

	int tomo2count = 0;
	Sprite tomodati2(L"friend2.png");
	tomodati2.position = Float3(40.0f, -80.0f, 0.0f);
	tomodati2.scale = 0.35f;
	bool tomo2Flag = false;

	Sprite tomodati3(L"friend3.png");
	tomodati3.position = Float3(49.0f, -86.0f, 0.0f);
	tomodati3.scale = 0.275f;

	int tomo3count = 0;
	Sprite tomodati4(L"friend.png");
	tomodati4.position = Float3(0.0f, -112.0f, 0.0f);
	tomodati4.scale = 0.275f;
	bool tomo3Flag = false;

	int tomo4count = 0;
	Sprite tomodati5(L"friend2.png");
	tomodati5.position = Float3(0.0f, -112.0f, 0.0f);
	tomodati5.scale = 0.275f;
	bool tomo4Flag = false;

	Sprite tomodati6(L"friend3.png");
	tomodati6.position = Float3(5.0f, -117.0f, 0.0f);
	tomodati6.scale = 0.22f;

	int windcount = 0;
	float windspeed = 35.0f;
	Sprite wind(L"wind.png");
	wind.scale = 0.6f;
	wind.angles.z = -22.5;

	int wind2count = 0;
	float wind2speed = 30.0f;
	Sprite wind2(L"wind2.png");
	wind2.scale = 0.6f;
	wind2.angles.z = 22.5;

	float kameraspeed = 250.0f;
	Sprite kamera(L"kamera.png");
	kamera.scale.x = 0.82f;
	kamera.scale.y = 0.77f;
	Float3 kameraPosition(kameraspeed, kameraspeed, 0.0f);

	float kamera2speed = 250.0f;
	Sprite kamera2(L"kamera2.png");
	kamera2.scale.x = 0.82f;
	kamera2.scale.y = 0.77f;
	Float3 kamera2Position(kamera2speed, kamera2speed, 0.0f);

	Sprite title(L"ƒ^ƒCƒgƒ‹.png");
	title.scale = 0.81f;

	Sprite tutorial(L"setumei.png");
	tutorial.scale = 0.65;

	Sprite stage(L"stage.png");
	stage.scale = 0.81f;

	Sprite gazou(L"satuei.png");
	gazou.scale = 0.472f;

	Sprite gazou2(L"satuei2.png");
	gazou2.scale = 0.472f;

	Sprite gameclear(L"clear.png");
	gameclear.scale = 0.1175f;

	Sprite gameclear2(L"clear2.png");
	gameclear2.scale = 0.472f;

	Sprite stage2(L"stage2.png");
	stage2.scale = 0.7f;

	Sprite over(L"gameover.png");
	over.scale = 0.85f;

	Sprite background(L"haikei.png");
	background.scale = 0.85f;

	Sprite background2(L"haikei2.png");
	background2.scale.x = 0.71f;
	background2.scale.y = 0.85f;

	Sound soundkamera(L"kamera.wav");
	Sound soundwind(L"wind.wav");
	bool soundFlag = false;
	Sound soundgameover(L"gameover.wav");
	Sound soundBGM(L"BGM.wav");

	App::SetWindowSize(842, 595);

	while (App::Refresh())
	{
		camera.Update();

		switch (mode)
		{
		case Title:

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Tutorial;
			}

			title.Draw();

			break;

		case Tutorial:

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Stage1;
			}

			tutorial.Draw();

			break;

		case Stage1:

			soundwind.SetVolume(0.01f);
			soundwind.Play();

			if (App::GetKeyDown(VK_SPACE))
			{
				srand((unsigned)time(NULL));

				wind.position = Position();

 				girl.position = Float3(
					-70.0f, -80.0f, 0.0f
				);

				tomodati.position = Float3(
					40.0f, -80.0f, 0.0f
				);

				girlFlag = false;
				tomoFlag = false;
				tomo2Flag = false;
				soundFlag = false;

				count = 0;
				girlcount = 0;
				tomocount = 0;
				tomo2count = 0;

				soundwind.Stop();
				soundwind.SetVolume(1.0f);

				soundBGM.Play();
				mode = Game;
			}

			camera.position = 0.0f;

			stage.Draw();

			break;

		case Game:

			background.Draw();

			if (wind.position.x > girl.position.x)
			{
				girlFlag = true;
			}

			if (girlFlag == true)
			{
				if (App::GetKeyDown(VK_SPACE))
				{
					if (kamera.position.x < App::GetWindowSize().x &&
						kamera.position.x > -App::GetWindowSize().x &&
						kamera.position.y < App::GetWindowSize().y &&
						kamera.position.y > -App::GetWindowSize().y &&
						tomo2Flag == true)
					{
					}
					else
					{
						soundkamera.Play();
						soundBGM.Stop();
						mode = Gazou;
					}
				}
				girlcount++;
				if (girlcount > 15)
				{
					girlFlag = false;
				}
				girl2.Draw();
			}
			else
			{
				girlcount = 0;
				girl.Draw();
			}

			if (tomoFlag == false &&
				tomo2Flag == false &&
				rand() / (float)RAND_MAX < 0.007 &&
				count++ > 1)
			{
				tomoFlag = true;
			}

			if (tomoFlag == true)
			{
				tomocount++;
				if (tomocount > 60)
				{
					tomoFlag = false;
				}
				tomodati2.Draw();
			}
			else
			{
				tomocount = 0;
				if (tomo2Flag == false)
				{
					tomodati.Draw();
				}
			}

			if (tomocount > 60)
			{
				tomo2Flag = true;
			}

			if (tomo2Flag == true)
			{
				if (kamera.position.x < App::GetWindowSize().x &&
					kamera.position.x > -App::GetWindowSize().x &&
					kamera.position.y < App::GetWindowSize().y &&
					kamera.position.y > -App::GetWindowSize().y &&
					tomo2count > 120)
				{
					soundgameover.Play();
					soundBGM.Stop();
					mode = Gameover;
				}
				tomo2count++;
				if (tomo2count > 121)
				{
					tomo2Flag = false;
				}
				tomodati3.Draw();
			}
			else
			{
				tomo2count = 0;
			}

			wind.position.x += windspeed;

			if (wind.position.x > App::GetWindowSize().x / 2.0f)
			{
				soundFlag = false;
				wind.position = Position();
			}
			if (soundFlag == false &&
				wind.position.x > -App::GetWindowSize().x / 2.0f - 500.0f)
			{
				soundFlag = true;
				soundwind.Play();
			}
			wind.Draw();

			if (App::GetKey(VK_SPACE) &&
				tomo2Flag == false)
			{
				kamera.position.x -= kameraspeed;
				kamera.position.y -= kameraspeed * 1.5f;
			}
			if (App::GetKeyUp(VK_SPACE) &&
				tomo2Flag == true)
			{
				kamera.position.x = 0.0f;
				kamera.position.y = 0.0f;
			}
			if (App::GetKeyUp(VK_SPACE) &&
				tomo2Flag == false)
			{
				kamera.position.x = 0.0f;
				kamera.position.y = 0.0f;
			}

			kamera.Draw();

			break;

		case Gazou:

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Gameclear;
			}

			gazou.Draw();

			break;

		case Gameclear:

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Stage2;
			}

			gameclear.Draw();

			break;

		case Gameover:

			if (App::GetKeyDown(VK_SPACE))
			{
				soundgameover.Stop();
				mode = Stage1;
			}

			over.Draw();

			break;

		case Stage2:

			soundwind.SetVolume(0.01f);
			soundwind.Play();

			if (App::GetKeyDown(VK_SPACE))
			{
				srand((unsigned)time(NULL));

				wind2.position = Position2();

				girl3.position = Float3(
					-105.0f, -117.0f, 0.0f
				);

				tomodati4.position = Float3(
					0.0f, -112.0f, 0.0f
				);

				girl3Flag = false;
				tomo3Flag = false;
				tomo4Flag = false;
				soundFlag = false;

				count = 0;
				girl3count = 0;
				tomo3count = 0;
				tomo4count = 0;

				soundwind.Stop();
				soundwind.SetVolume(1.0f);

				soundBGM.Play();
				mode = Game2;
			}

			stage2.Draw();

			break;

		case Game2:

			background2.Draw();

			if (wind2.position.x < girl3.position.x)
			{
				girl3Flag = true;
			}

			if (girl3Flag == true)
			{
				if (App::GetKeyDown(VK_SPACE))
				{
					if (kamera2.position.x < App::GetWindowSize().x &&
						kamera2.position.x > -App::GetWindowSize().x &&
						kamera2.position.y < App::GetWindowSize().y &&
						kamera2.position.y > -App::GetWindowSize().y &&
						tomo4Flag == true)
					{
					}
					else
					{
						soundkamera.Play();
						soundBGM.Stop();
						mode = Gazou2;
					}
				}
				girl3count++;
				if (girl3count > 15)
				{
					girl3Flag = false;
				}
				girl4.Draw();
			}
			else
			{
				girl3count = 0;
				girl3.Draw();
			}

			if (tomo3Flag == false &&
				tomo4Flag == false &&
				rand() / (float)RAND_MAX < 0.01 &&
				count++ > 1)
			{
				tomo3Flag = true;
			}

			if (tomo3Flag == true)
			{
				tomo3count++;
				if (tomo3count > 60)
				{
					tomo3Flag = false;
				}
				tomodati5.Draw();
			}
			else
			{
				tomo3count = 0;
				if (tomo4Flag == false)
				{
					tomodati4.Draw();
				}
			}

			if (tomo3count > 60)
			{
				tomo4Flag = true;
			}

			if (tomo4Flag == true)
			{
				if (kamera2.position.x < App::GetWindowSize().x &&
					kamera2.position.x > -App::GetWindowSize().x &&
					kamera2.position.y < App::GetWindowSize().y &&
					kamera2.position.y > -App::GetWindowSize().y &&
					tomo4count > 120)
				{
					soundgameover.Play();
					soundBGM.Stop();
					mode = Gameover2;
				}
				tomo4count++;
				if (tomo4count > 121)
				{
					tomo4Flag = false;
				}
				tomodati6.Draw();
			}
			else
			{
				tomo4count = 0;
			}

			wind2.position.x -= wind2speed;

			if (wind2.position.x < -App::GetWindowSize().x / 2.0f)
			{
				soundFlag = false;
				wind2.position = Position2();
			}
			if (soundFlag == false &&
				wind2.position.x < App::GetWindowSize().x / 2.0f + 500.0f)
			{
				soundFlag = true;
				soundwind.Play();
			}
			wind2.Draw();

			if (App::GetKey(VK_SPACE) &&
				tomo4Flag == false)
			{
				kamera2.position.x -= kamera2speed;
				kamera2.position.y -= kamera2speed * 1.5f;
			}
			if (App::GetKeyUp(VK_SPACE) &&
				tomo4Flag == true)
			{
				kamera2.position.x = 0.0f;
				kamera2.position.y = 0.0f;
			}
			if (App::GetKeyUp(VK_SPACE) &&
				tomo4Flag == false)
			{
				kamera2.position.x = 0.0f;
				kamera2.position.y = 0.0f;
			}

			kamera2.Draw();

			break;

		case Gazou2:

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Gameclear2;
			}

			gazou2.Draw();

			break;

		case Gameclear2:

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Title;
			}

			gameclear2.Draw();

			break;

		case Gameover2:

			if (App::GetKeyDown(VK_SPACE))
			{
				soundgameover.Stop();
				mode = Stage2;
			}

			over.Draw();

			break;
		}
	}
	return 0;
}