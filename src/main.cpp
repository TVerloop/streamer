/**
 * @file    main.cpp
 * @author   <tom@vivobook>
 * @version 1.0
 * @date    27-06-2019
 *
 *
 */


#include <streambuf>

template<class  CharT, class Traits = std::char_traits<CharT>>
class basic_sockbuf : public std::basic_streambuf<CharT, Traits> {
public:

    using char_type   = CharT;
    using traits_type = Traits;
    using int_type    = typename Traits::int_type;
    using pos_type    = typename Traits::pos_type;
    using off_type    = typename Traits::off_type;

    basic_sockbuf() : std::basic_streambuf<CharT, Traits>() {

    }

    basic_sockbuf(const basic_sockbuf& rhs) = delete;
    basic_sockbuf(basic_sockbuf&& rhs);

    basic_sockbuf& operator=(basic_sockbuf&& rhs);
    basic_sockbuf& operator=(const basic_sockbuf& rhs) = delete;

    void swap(basic_sockbuf& rhs);

    virtual ~basic_sockbuf();

protected:

    virtual void imbue(const std::locale& loc) override;

    virtual std::basic_streambuf<CharT, Traits>* setbuf(char_type* s, std::streamsize n) override;

    virtual pos_type seekoff(off_type off, std::ios_base::seekdir dir,
                             std::ios_base::openmode which = std::ios_base::in | std::ios_base::out) override;

    virtual pos_type seekpos(pos_type pos,
                             std::ios_base::openmode which = std::ios_base::in | std::ios_base::out) override;

    virtual int sync() override;

    virtual std::streamsize showmanyc() override;

    virtual int_type underflow() override;

    virtual int_type uflow() override;

    virtual std::streamsize xsgetn(char_type* s, std::streamsize count) override;

    virtual std::streamsize xsputn(const char_type* s, std::streamsize count) override;

    virtual int_type overflow(int_type ch = Traits::eof()) override;

    virtual int_type pbackfail(int_type c = Traits::eof()) override;

};




int main(int argc, char** argv) {
    return 0;
}
