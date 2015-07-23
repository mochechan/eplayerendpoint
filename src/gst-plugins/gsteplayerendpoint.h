#ifndef _GST_EPLAYERENDPOINT_H_
#define _GST_EPLAYERENDPOINT_H_

#include <gst/video/gstvideofilter.h>

G_BEGIN_DECLS
#define GST_TYPE_EPLAYERENDPOINT   (gst_eplayerendpoint_get_type())
#define GST_EPLAYERENDPOINT(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_EPLAYERENDPOINT,Gsteplayerendpoint))
#define GST_EPLAYERENDPOINT_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_EPLAYERENDPOINT,GsteplayerendpointClass))
#define GST_IS_EPLAYERENDPOINT(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_EPLAYERENDPOINT))
#define GST_IS_EPLAYERENDPOINT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_EPLAYERENDPOINT))
typedef struct _Gsteplayerendpoint Gsteplayerendpoint;
typedef struct _GsteplayerendpointClass GsteplayerendpointClass;
typedef struct _GsteplayerendpointPrivate GsteplayerendpointPrivate;

struct _Gsteplayerendpoint
{
  GstVideoFilter base;
  GsteplayerendpointPrivate *priv;
};

struct _GsteplayerendpointClass
{
  GstVideoFilterClass base_eplayerendpoint_class;
};

GType gst_eplayerendpoint_get_type (void);

gboolean gst_eplayerendpoint_plugin_init (GstPlugin * plugin);

G_END_DECLS
#endif /* _GST_EPLAYERENDPOINT_H_ */
