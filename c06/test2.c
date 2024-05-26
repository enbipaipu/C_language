#include <stdio.h>

// 構造体を定義する
struct student
{
    char name[50];
    const char student_id[10];
    int course_id;
    float score;
};

// struct student 型に別名をつける
typedef struct student student_t;

// 学生の成績を修正する
void changeScore(student_t *someone, float newScore)
{
    // 構造体ポインタによりメンバのscoreの値を修正する。
    someone->score = newScore;
}

int main()
{
    // 構造体変数の宣言と初期化を行う
    student_t enryo = {
        .name = "Inoue",
        .student_id = "S000012345",
        .course_id = 1,
        .score = 88.5,
    };

    // 構造体変数(enryo)のポインタを受け渡す
    changeScore(&enryo, 85.);

    // 構造体変数(enryo)のメンバの参照を行う
    printf("name: %s, score: %f\n", enryo.name, enryo.score);
    return 0;
}