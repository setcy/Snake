#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller() : score(0), beginlen(0) {}
    void Start();
    void Select();
    void Selectdifficulty();
    void DrawGame();
    int PlayGame();
    void UpdateScore(const int&);
    void RewriteScore();
    int Menu();
    void Game();
    int GameOver();
    int getkey();
private:
    int key;
    float speed;
    int score;
    int beginlen;
    int beginflag;
    int liveflag;//生存模式flag
};
#endif // CONTROLLER_H
