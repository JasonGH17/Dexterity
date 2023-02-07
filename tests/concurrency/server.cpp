#include "dexterity.h"

using namespace Dexterity::Server;


class NewController : public HTTPController
{
public:
    NewController(std::string path) : HTTPController(path)
    {
        handleGet("/test", handler(NewController::test));
    };

    const char *test(HTTPRequest *req, HTTPResponse *res)
    {
        (void)req;
        res->statusCode = 200;
        res->headers.push_back(HTTPHeader{"Content-Type", "text/html"});
        sleep(1);
        return "<h1>Hello world</h1><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed nec consectetur ante. Nullam nisi dolor, malesuada id pulvinar et, tempor ac ipsum. Vivamus dapibus pulvinar leo. Fusce finibus turpis vitae neque feugiat, vel tincidunt tellus accumsan. Morbi bibendum ligula sed ullamcorper accumsan. Vestibulum et interdum neque, ac tempor leo. Suspendisse felis lacus, hendrerit ac feugiat eget, fermentum sed libero. Mauris dictum elit aliquet faucibus fermentum. Etiam ante felis, fermentum sit amet tempor eu, sodales suscipit augue. Maecenas facilisis justo urna, nec dignissim odio placerat eget. Mauris ullamcorper leo sit amet tristique viverra. Donec fringilla risus sit amet diam finibus interdum. Pellentesque erat sapien, tincidunt at magna ac, aliquam ornare ante. Vivamus gravida lacinia nibh, ut convallis odio egestas sed.\nMaecenas elementum pretium nibh, eu mollis enim dignissim ac. In ornare scelerisque dui, at imperdiet turpis feugiat at. Fusce nunc dolor, dictum eget rhoncus vel, ultricies in massa. Ut turpis dolor, rhoncus sit amet est et, viverra vulputate arcu. Quisque nec enim quis sapien dignissim posuere vestibulum id erat. Nunc mollis lacinia pharetra. Mauris vitae risus eget elit iaculis mattis vitae et metus. Mauris condimentum nisl convallis tortor bibendum rhoncus. Quisque et gravida quam. Fusce neque leo, vehicula vel magna quis, finibus gravida magna. Sed tempor tempor purus, nec finibus nisl faucibus nec. Praesent at lobortis tortor, quis maximus erat. Aliquam laoreet risus turpis, non finibus lorem aliquam vel. Suspendisse maximus sapien sapien, vitae aliquet ante suscipit sit amet. Sed sit amet mi sodales, rhoncus urna quis, faucibus ante. Ut feugiat enim diam, at condimentum ipsum aliquet id.\nPraesent tempus, ex vitae convallis dignissim, ipsum turpis accumsan libero, commodo rutrum nisi mi et nisl. Duis suscipit, erat vitae placerat molestie, neque erat ullamcorper tortor, suscipit finibus nulla dui et turpis. Vivamus facilisis ullamcorper quam. Proin efficitur dui vitae nibh sollicitudin condimentum. Proin ac ultrices magna. Morbi sollicitudin lacus purus, in finibus velit maximus in. Proin libero libero, ultricies non eleifend quis, tincidunt et est. Nunc ut sodales quam, a pellentesque nunc.\nMauris nulla massa, tincidunt eget dignissim vitae, ornare in quam. Cras commodo quis leo eu convallis. Proin pretium magna leo, non ornare lorem vehicula vel. Suspendisse orci mauris, finibus ut hendrerit vel, consequat ac lacus. Cras turpis sapien, dictum ut nulla id, bibendum sodales lectus. Ut sagittis libero in semper condimentum. Quisque ac faucibus sapien.\nNam blandit tincidunt dui, eu consectetur tellus ullamcorper at. Sed feugiat dictum massa, vitae tincidunt tortor accumsan sollicitudin. Quisque ultricies nisi in ante condimentum ultrices. Quisque fringilla faucibus aliquam. Sed nec massa id elit ornare ullamcorper sed ut lectus. Nulla facilisi. Integer ante est, varius eu feugiat id, faucibus in orci. Quisque id lorem euismod, vehicula quam eget, accumsan dui. Curabitur nulla dolor, cursus vitae mauris quis, fringilla maximus diam. Praesent pellentesque purus eget arcu pulvinar, ut fringilla magna blandit. Nam facilisis dignissim massa elementum vehicula. Nunc vel magna ac erat consectetur pretium. Vestibulum velit lectus, venenatis ut scelerisque et, euismod ac dolor.</p>";
    }
};

int main()
{
    Dexterity::Application app = Dexterity::Application();

    app.mapController<NewController>("");

    app.start();

    return 0;
}