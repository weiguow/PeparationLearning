/*
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：享元模式
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * 枚举名：Piece_COLOR
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：棋子颜色
 * 版本：1.0
 */
enum PIECE_COLOR {
    BLACK, WHITE
};

/*
 * 结构体名：PiecePos
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：棋子位置
 * 版本：1.0
 */
struct PiecePos {
    int x;
    int y;
    PiecePos(int a, int b) : x(a), y(b) {}
};

/*
 * 类名：Piece
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：棋子定义
 */
class Piece {
protected:
    PIECE_COLOR m_color;
public:
    Piece(PIECE_COLOR color) : m_color(color) {}
    ~Piece() {}

    virtual void draw() {}
};

/*
 * 类名：BlackPiece
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：绘制一颗黑棋
 */
class BlackPiece : public Piece {
public:
    BlackPiece(PIECE_COLOR color) : Piece(color) {}
    ~BlackPiece() {}

    void draw() { cout << "绘制一颗黑棋\n"; }
};

/*
 * 类名：WhitePiece
 * 作者：cooooooooooooooool
 * 编写日期：18-9-10
 * 功能描述：绘制一颗白棋
 */
class WhitePiece : public Piece {
public:
    WhitePiece(PIECE_COLOR color) : Piece(color) {}
    ~WhitePiece() {}

    void draw() { cout << "绘制一颗白棋\n"; }
};

/*
 * 类名：PieceBoard
 * 作者：cooooooooooooooool
 * 编写日期：18-9-15
 * 功能描述：定义棋盘
 */
class PieceBoard {
private:
    vector<PiecePos> m_vec_pos;  /*存放棋子的位置*/
    Piece *m_black_piece;  /*黑棋棋子*/
    Piece *m_white_piece;  /*白棋棋子*/
    string m_black_name;
    string m_white_name;
public:
    PieceBoard(string black, string white) : m_black_name(black), m_white_name(white) {
        m_black_piece = NULL;
        m_white_piece = NULL;
    }

    ~PieceBoard() {
        delete m_black_piece;
        delete m_white_piece;
    }

    void set_piece(PIECE_COLOR color, PiecePos pos) {
        if (color == BLACK) {
            if (m_black_piece == NULL)
                m_black_piece = new BlackPiece(color);
            cout << m_black_name << "在位置(" << pos.x << ',' << pos.y << ")";
            m_black_piece->draw();
        } else {
            if (m_white_piece == NULL)
                m_white_piece = new WhitePiece(color);
            cout << m_white_name << "在位置(" << pos.x << ',' << pos.y << ")";
            m_white_piece->draw();
        }
        m_vec_pos.push_back(pos);
    }
};

int main() {
    PieceBoard piece_board("A", "B");
    piece_board.set_piece(BLACK, PiecePos(4, 4));
    piece_board.set_piece(WHITE, PiecePos(4, 16));
    piece_board.set_piece(BLACK, PiecePos(16, 4));
    piece_board.set_piece(WHITE, PiecePos(16, 16));
    int goods_price = 0;
}