#ifndef GRAPHE_LINE_H
#define GRAPHE_LINE_H


class Line {
    int posX;
    int posY;
    int vecX;
    int vecY;
    bool center;

public:
    Line() noexcept = default;
    constexpr Line(int x1, int y1, int x2, int y2, bool c) noexcept: posX(x1), posY(y1), vecX(x2), vecY(y2), center(c) {}

    inline void setAll(int x1, int y1, int x2, int y2) noexcept {posY=x1; posY=y1; vecX=x2; vecY=y2;}
    int getPosX() const noexcept {return posX;}
    int getPosY() const noexcept {return posY;}
    int getVecX() const noexcept {return vecX;}
    int getVecY() const noexcept {return vecY;}
    bool isCenter() const noexcept {return center;}

    ~Line() noexcept = default;
};


#endif //GRAPHE_LINE_H
