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
            uint16_t Position;
        private:
            std::string content;
            LineBreak lb;
    };

    Line::Line(std::string content) {
        this->content = content;
        this->lb = None;
        this->Position = 0;
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
            size_t GetSize();
            void GoUp();
            void GoDown();

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

    size_t Buffer::GetSize() {
        return lines.size();
    }

    void Buffer::GoUp() {
        if (ActiveLine == 0) {
            return;
        }

        ActiveLine--;
    }

    void Buffer::GoDown() {
        if (ActiveLine >= lines.size() - 1) {
            return;
        }

        ActiveLine++;
    }
}

#endif
