#ifndef JIF_BUFFER
#define JIF_BUFFER

#include <vector>
#include <string>

namespace JIF {
    enum LineBreak {None, Windows, Linux, Mac};

    class Line {
        public:
            Line(std::string content);
            std::string GetContent();
            void PutLast(const char c);
            void PutLast(const char * c);
            void PutAfter(const char c);
            void PutAfter(const char * c);
            void DeleteBefore();
            void GoLast();
            void GoLeft();
            void GoRight();
            uint16_t Position = 0;
        private:
            std::string content;
            LineBreak lb;
    };

    Line::Line(std::string content) {
        this->content = content;
        this->lb = None;
    }

    std::string Line::GetContent() {
        return content;
    }

    void Line::PutLast(const char c) {
        content.append(1u, c);
        GoLast();
    }

    void Line::PutLast(const char * c) {
        content.append(c);
        GoLast();
    }

    void Line::PutAfter(const char c) {
        content.insert(Position, 1u, c);
        Position++;
    }

    void Line::PutAfter(const char * c) {
        content.insert(Position, c);
        Position++;
    }

    void Line::GoLast() {
        Position = content.size();
    }

    void Line::GoLeft() {
        if (Position <= 0) {
            return;
        }
        Position--;
    }

    void Line::GoRight() {
        if (Position >= content.size()) {
            return;
        }
        Position++;
    }

    void Line::DeleteBefore() {
        if (content.size() == 0) {
            return;
        }
        content.erase(Position-1, 1);
        Position--;
    }

    class Buffer {
        public:
            Buffer();
            void Append(Line line);
            Line* GetLine(unsigned int n);
            uint32_t ActiveLine = 0;
        private:
            std::vector<Line> lines;
    };

    Buffer::Buffer() {
    }

    void Buffer::Append(Line line) {
        lines.push_back(line);
        ActiveLine = lines.size() - 1;
    }

    Line* Buffer::GetLine(unsigned int n) {
        return &(lines[n]);
    }
}

#endif
