/* Autogenerated with kurento-module-creator */

#include <gst/gst.h>
#include "MediaPipeline.hpp"
#include <eplayerendpointImplFactory.hpp>
#include "eplayerendpointImpl.hpp"
#include <jsonrpc/JsonSerializer.hpp>
#include <KurentoException.hpp>

#define GST_CAT_DEFAULT kurento_eplayerendpoint_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoeplayerendpointImpl"

#define FACTORY_NAME "eplayerendpoint"

namespace kurento
{
namespace module
{
namespace eplayerendpoint
{

static void
adaptor_function (GstElement *player, gpointer data)
{
  auto handler = reinterpret_cast<std::function<void() >*> (data);

  (*handler) ();
}

eplayerendpointImpl::eplayerendpointImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline, const std::string &filesrc, bool useEncodedMedia)  : UriEndpointImpl (config, std::dynamic_pointer_cast<MediaObjectImpl> (mediaPipeline), FACTORY_NAME, filesrc)
{
	FILE *f = fopen("/tmp/out_file.txt", "a");
	if (f == NULL) {
		printf("Error opening file!\n");
		return;
	}
	// to get current time
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	/* print: integers floats character text*/
	int i = 1;
	float py = 3.1415927;
	char c = 'A';
	const char *text = "Write this to the file, constructor";
	printf("Integer: %d, float: %f, a character: %c, string: %s, time: %s \n", i, py, c, text, asctime(timeinfo));
	fprintf(f, "Integer: %d, float: %f, a character: %c, string: %s, time: %s \n", i, py, c, text, asctime(timeinfo));
	fclose(f);

  // FIXME: Implement this
  GstElement *element = getGstreamerElement();

  g_object_set (G_OBJECT (element), "use-encoded-media", useEncodedMedia, NULL);

  // any external variable is implicitly captured by reference if used in anonymous function
  eosLambda = [&] () {
    try {
      EndOfStream event (shared_from_this(), EndOfStream::getName() );

      signalEndOfStream (event);
    } catch (std::bad_weak_ptr &e) {
    }
  };

  invalidFileSrcLambda = [&] () {
    try {
      /* TODO: Define error codes and types*/
      Error error (shared_from_this(), "Invalid FileSrc", 0, "INVALID_FileSrc");

      signalError (error);
    } catch (std::bad_weak_ptr &e) {
    }
  };

  invalidMediaLambda = [&] () {
    try {
      /* TODO: Define error codes and types*/
      Error error (shared_from_this(), "Invalid Media", 0, "INVALID_MEDIA");

      signalError (error);
    } catch (std::bad_weak_ptr &e) {
    }
  };

  signalEOS = g_signal_connect (element, "eos", G_CALLBACK (adaptor_function),
                                &eosLambda);
  signalInvalidFileSrc = g_signal_connect (element, "invalid-uri",
                                       G_CALLBACK (adaptor_function),
                                       &invalidFileSrcLambda);
  signalInvalidMedia = g_signal_connect (element, "invalid-media",
                                         G_CALLBACK (adaptor_function),
                                         &invalidMediaLambda);
}

eplayerendpointImpl::~eplayerendpointImpl ()
{
  g_signal_handler_disconnect (element, signalEOS);
  g_signal_handler_disconnect (element, signalInvalidMedia);
  g_signal_handler_disconnect (element, signalInvalidFileSrc);
  stop();
}

void eplayerendpointImpl::play ()
{
	FILE *f = fopen("/tmp/out_file.txt", "a");
	if (f == NULL) {
		printf("Error opening file!\n");
		return;
	}
	// to get current time
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	/* print: integers floats character text*/
	int i = 1;
	float py = 3.1415927;
	char c = 'A';
	const char *text = "Write this to the file, play";
	printf("Integer: %d, float: %f, a character: %c, string: %s, time: %s \n", i, py, c, text, asctime(timeinfo));
	fprintf(f, "Integer: %d, float: %f, a character: %c, string: %s, time: %s \n", i, py, c, text, asctime(timeinfo));
	fclose(f);
  start();
  // FIXME: Implement this
  throw KurentoException (NOT_IMPLEMENTED, "eplayerendpointImpl::play: Not implemented");
}

MediaObjectImpl *
eplayerendpointImplFactory::createObject (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline, const std::string &filesrc, bool useEncodedMedia) const
{
  return new eplayerendpointImpl (config, mediaPipeline, filesrc, useEncodedMedia);
}

eplayerendpointImpl::StaticConstructor eplayerendpointImpl::staticConstructor;

eplayerendpointImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

} /* eplayerendpoint */
} /* module */
} /* kurento */
