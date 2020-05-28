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
            void DeleteBefore();
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
    }

    void Line::PutLast(const char * c) {
        content.append(c);
    }

    void Line::DeleteBefore() {
        if (content.size() == 0) {
            return;
        }
        content.erase(content.end()-1, content.end());
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
