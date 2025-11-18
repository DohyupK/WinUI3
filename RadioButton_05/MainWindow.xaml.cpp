#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#include "winrt/Microsoft.UI.Xaml.Media.Imaging.h"          // image용
#include "string"                                           // string용
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;          // PersonPicture용
using namespace Microsoft::UI::Xaml::Media::Imaging;    // image용
using namespace Microsoft::UI::Xaml::Media;             // image용
using namespace Windows::Foundation;                    // URI용
using namespace std;                                    // 편의용 std
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::RadioButton_05::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}

void winrt::RadioButton_05::implementation::MainWindow::ProfileImageRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    string st = "You selected Option 1 ";               // 텍스트 박스에 넣을 문구
    aaa().Text(to_hstring(st));                         // 텍스트 박스에 문구 출력

    Image img;                                          // 이미지
    BitmapImage bimg;                                   // 비트맵 이미지
    Uri uri = Uri(to_hstring("https://docs.microsoft.com/windows/uwp/contacts-and-calendar/images/shoulder-tap-static-payload.png"));   // Uri 설정
    bimg.UriSource(uri);                                // 비트맵 이미지에 Uri소스 설정
    img.Source() = bimg;                                // 이미지 소스에 비트맵 Uri소스 설정
    personPicture().ProfilePicture(bimg);               // 프로필에 이미지 설정
}

void winrt::RadioButton_05::implementation::MainWindow::DisplayNameRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    string st = "You selected Option 2 ";               // 텍스트 박스에 넣을 문구
    aaa().Text(to_hstring(st));                         // 텍스트 박스에 문구 출력

    personPicture().ProfilePicture(NULL);               // 프로필에 이미지 삭제
    personPicture().Initials(to_hstring(""));           // 프로필에 이니셜 삭제
    personPicture().DisplayName(to_hstring("Jane Doe"));// 프로필에 이름 설정
}

void winrt::RadioButton_05::implementation::MainWindow::InitialRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    string st = "You selected Option 3 ";               // 텍스트 박스에 넣을 문구
    aaa().Text(to_hstring(st));                         // 텍스트 박스에 문구 출력

    personPicture().ProfilePicture(NULL);               //프로필 이미지 삭제
    personPicture().Initials(to_hstring("SB"));         // 프로필에 이니셜 설정
}
