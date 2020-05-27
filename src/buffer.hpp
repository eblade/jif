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

    class Buffer {
        public:
            Buffer();
            void Append(Line line);
            Line* GetLine(unsigned int n);
        private:
            std::vector<Line> lines;
    };

    Buffer::Buffer() {
    }

    void Buffer::Append(Line line) {
        lines.push_back(line);
    }

    Line* Buffer::GetLine(unsigned int n) {
        return &(lines[n]);
    }
}

#endif
