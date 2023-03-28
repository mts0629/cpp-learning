// Class
class Rectangle {
public:
    // Public data members
    int height_;
    int width_;
};

int main() {
    Rectangle r;
    r.height_ = 10;
    r.width_ = 20;

    Rectangle* pr = &r;
    // Poitner accesss
    (*pr).height_ = 10;
    (*pr).width_ = 20;
    pr->height_ = 10;
    pr->width_ = 20;
}
