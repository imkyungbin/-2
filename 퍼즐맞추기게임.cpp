#include<Bangtal.h>
#pragma comment(lib, "Bangtal.lib")

SceneID scene1, scene2;
ObjectID startb, endb, qorudemf[11], gmlsqorud;

int gmlsqorudx = 960, gmlsqorudy = 0;
int qorudx[11] = { 0,320,640,960,0,320,640,960,0,320,640 };
int qorudy[11] = { 480,480,480,480,240,240,240,240,0,0,0 };
int fqorudx[11] = { 640,320,640,0,960,320,960,640,320,0,0 };
int fqorudy[11] = { 0,480,480,240,480,240,240,240,0,0,480 };

ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(name, image);

	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}
	return object;
}




void endGame(bool success) {
	if (success) {
		showMessage("¼º°ø!");
		enterScene(scene1);
		hideObject(startb);
		setObjectImage(startb, "´Ù½Ã½ÃÀÛ.png");
		showObject(startb);
		showObject(endb);
	}

}

void complete() {
	if (fqorudx[0] == qorudx[0] && fqorudy[0] == qorudy[0] && fqorudx[1] == qorudx[1] && fqorudy[1] == qorudy[1] && fqorudx[2] == qorudx[2] && fqorudy[2] == qorudy[2] && fqorudx[3] == qorudx[3] && fqorudy[3] == qorudy[3] && fqorudx[4] == qorudx[4] && fqorudy[4] == qorudy[4] && fqorudx[5] == qorudx[5] && fqorudy[5] == qorudy[5] && fqorudx[6] == qorudx[6] && fqorudy[6] == qorudy[6] && fqorudx[7] == qorudx[7] && fqorudy[7] == qorudy[7] && fqorudx[8] == qorudx[8] && fqorudy[8] == qorudy[8] && fqorudx[9] == qorudx[9] && fqorudy[9] == qorudy[9] && fqorudx[10] == qorudx[10] && fqorudy[10] == qorudy[10] && fqorudx[11] == qorudx[11] && fqorudy[11] == qorudy[11]) {
		endGame(true);
	}
}

void startGame() {
	hideObject(startb);
	hideObject(endb);
	enterScene(scene2);

}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {


	if (object == endb) {
		endGame();
	}
	else if (object == startb) {
		startGame();
	}
	for (int i = 0; i < 11; i++) {
		if (object == qorudemf[i]) {
			if (fqorudx[i] + 320 == gmlsqorudx && fqorudy[i] == gmlsqorudy) {
				fqorudx[i] += 320;
				gmlsqorudx -= 320;
				locateObject(qorudemf[i], scene2, fqorudx[i], fqorudy[i]);
				locateObject(gmlsqorud, scene2, gmlsqorudx, gmlsqorudy);
				complete();
			}
			else if (fqorudx[i] - 320 == gmlsqorudx && fqorudy[i] == gmlsqorudy) {
				fqorudx[i] -= 320;
				gmlsqorudx += 320;
				locateObject(qorudemf[i], scene2, fqorudx[i], fqorudy[i]);
				locateObject(gmlsqorud, scene2, gmlsqorudx, gmlsqorudy);
				complete();


			}
			else if (fqorudy[i] + 240 == gmlsqorudy && fqorudx[i] == gmlsqorudx) {
				fqorudy[i] += 240;
				gmlsqorudy -= 240;
				locateObject(qorudemf[i], scene2, fqorudx[i], fqorudy[i]);
				locateObject(gmlsqorud, scene2, gmlsqorudx, gmlsqorudy);
				complete();
			}
			else if (fqorudy[i] - 240 == gmlsqorudy && fqorudx[i] == gmlsqorudx) {
				fqorudy[i] -= 240;
				gmlsqorudy += 240;
				locateObject(qorudemf[i], scene2, fqorudx[i], fqorudy[i]);
				locateObject(gmlsqorud, scene2, gmlsqorudx, gmlsqorudy);
				complete();
			}
		}
	}

}

int main() {
	setMouseCallback(mouseCallback);

	scene1 = createScene("ÆÛÁñ¸ÂÃß±â", "¿¤»ç¹è°æ.jpg");
	scene2 = createScene("ÆÛÁñ¸ÂÃß±â", "Èò¹è°æ.png");

	qorudemf[0] = createObject("qorud0", "¿¤»ç¹è°æ_01.png", scene2, fqorudx[0], fqorudy[0], true);
	qorudemf[1] = createObject("qorud1", "¿¤»ç¹è°æ_02.png", scene2, fqorudx[1], fqorudy[1], true);
	qorudemf[2] = createObject("qorud2", "¿¤»ç¹è°æ_03.png", scene2, fqorudx[2], fqorudy[2], true);
	qorudemf[3] = createObject("qorud3", "¿¤»ç¹è°æ_04.png", scene2, fqorudx[3], fqorudy[3], true);
	qorudemf[4] = createObject("qorud4", "¿¤»ç¹è°æ_05.png", scene2, fqorudx[4], fqorudy[4], true);
	qorudemf[5] = createObject("qorud5", "¿¤»ç¹è°æ_06.png", scene2, fqorudx[5], fqorudy[5], true);
	qorudemf[6] = createObject("qorud6", "¿¤»ç¹è°æ_07.png", scene2, fqorudx[6], fqorudy[6], true);
	qorudemf[7] = createObject("qorud7", "¿¤»ç¹è°æ_08.png", scene2, fqorudx[7], fqorudy[7], true);
	qorudemf[8] = createObject("qorud8", "¿¤»ç¹è°æ_09.png", scene2, fqorudx[8], fqorudy[8], true);
	qorudemf[9] = createObject("qorud9", "¿¤»ç¹è°æ_10.png", scene2, fqorudx[9], fqorudy[9], true);
	qorudemf[10] = createObject("qorud10", "¿¤»ç¹è°æ_11.png", scene2, fqorudx[10], fqorudy[10], true);
	gmlsqorud = createObject("gmlsqorud", "Èò¿¤»ç¹è°æ.png", scene2, gmlsqorudx, gmlsqorudy, true);
	startb = createObject("½ÃÀÛ", "½ÃÀÛ.png", scene1, 450, 200, true);
	endb = createObject("³¡", "³¡.png", scene1, 700, 200, true);

	startGame(scene1);
}