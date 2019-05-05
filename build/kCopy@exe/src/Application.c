/* Application.c generated by valac 0.40.15, the Vala compiler
 * generated from Application.vala, do not modify */



#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>


#define TYPE_APPLICATION (application_get_type ())
#define APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APPLICATION, Application))
#define APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APPLICATION, ApplicationClass))
#define IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APPLICATION))
#define IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APPLICATION))
#define APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APPLICATION, ApplicationClass))

typedef struct _Application Application;
typedef struct _ApplicationClass ApplicationClass;
typedef struct _ApplicationPrivate ApplicationPrivate;

#define TYPE_CLIP (clip_get_type ())
#define CLIP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CLIP, Clip))
#define CLIP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CLIP, ClipClass))
#define IS_CLIP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CLIP))
#define IS_CLIP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CLIP))
#define CLIP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CLIP, ClipClass))

typedef struct _Clip Clip;
typedef struct _ClipClass ClipClass;
enum  {
	APPLICATION_0_PROPERTY,
	APPLICATION_NUM_PROPERTIES
};
static GParamSpec* application_properties[APPLICATION_NUM_PROPERTIES];

#define TYPE_WINDOW (window_get_type ())
#define WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_WINDOW, Window))
#define WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_WINDOW, WindowClass))
#define IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_WINDOW))
#define IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_WINDOW))
#define WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_WINDOW, WindowClass))

typedef struct _Window Window;
typedef struct _WindowClass WindowClass;

#define TYPE_DATA (data_get_type ())
#define DATA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DATA, Data))
#define DATA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DATA, DataClass))
#define IS_DATA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DATA))
#define IS_DATA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DATA))
#define DATA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DATA, DataClass))

typedef struct _Data Data;
typedef struct _DataClass DataClass;
typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _Application {
	GtkApplication parent_instance;
	ApplicationPrivate * priv;
};

struct _ApplicationClass {
	GtkApplicationClass parent_class;
};

struct _ApplicationPrivate {
	Clip** clips;
	gint clips_length1;
	gint _clips_size_;
};

struct _Block1Data {
	int _ref_count_;
	Application* self;
	Window* window;
	Data* dat;
	GSettings* settings;
	gboolean first_run;
	GtkClipboard* clipboard;
};


static gpointer application_parent_class = NULL;

GType application_get_type (void) G_GNUC_CONST;
gpointer clip_ref (gpointer instance);
void clip_unref (gpointer instance);
GParamSpec* param_spec_clip (const gchar* name,
                             const gchar* nick,
                             const gchar* blurb,
                             GType object_type,
                             GParamFlags flags);
void value_set_clip (GValue* value,
                     gpointer v_object);
void value_take_clip (GValue* value,
                      gpointer v_object);
gpointer value_get_clip (const GValue* value);
GType clip_get_type (void) G_GNUC_CONST;
#define APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_APPLICATION, ApplicationPrivate))
Application* application_new (void);
Application* application_construct (GType object_type);
static void application_real_activate (GApplication* base);
GType window_get_type (void) G_GNUC_CONST;
GType data_get_type (void) G_GNUC_CONST;
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
Window* window_new (GtkApplication* application);
Window* window_construct (GType object_type,
                          GtkApplication* application);
Data* data_new (void);
Data* data_construct (GType object_type);
static void __lambda13_ (Block1Data* _data1_,
                  Clip** newClips,
                  int newClips_length1);
void window_DisplayClips (Window* self,
                          Clip** clips,
                          int clips_length1);
static void ___lambda13__data_row_callback (Data* _sender,
                                     Clip** clips,
                                     int clips_length1,
                                     gpointer self);
static void __lambda14_ (Block1Data* _data1_,
                  gboolean val);
static void ___lambda14__data_callback_event (Data* _sender,
                                       gboolean value,
                                       gpointer self);
void data_CreateTable (Data* self);
void data_GetClips (Data* self);
static void __lambda15_ (Block1Data* _data1_,
                  GdkEventOwnerChange* event);
void data_InsertClip (Data* self,
                      const gchar* value);
void application_Notify (Application* self,
                         const gchar* title,
                         const gchar* message);
static void ___lambda15__gtk_clipboard_owner_change (GtkClipboard* _sender,
                                              GdkEventOwnerChange* event,
                                              gpointer self);
static void __lambda16_ (Block1Data* _data1_,
                  Clip* clip);
void window_ResetClips (Window* self);
static void ___lambda16__data_insert_callback (Data* _sender,
                                        Clip* clip,
                                        gpointer self);
static void __lambda17_ (Block1Data* _data1_,
                  const gchar* value);
static void ___lambda17__window_on_clip_select (Window* _sender,
                                         const gchar* value,
                                         gpointer self);
static void __lambda18_ (Block1Data* _data1_);
void data_DropTable (Data* self);
static void ___lambda18__window_on_clear_data (Window* _sender,
                                        gpointer self);
static void __lambda19_ (Block1Data* _data1_,
                  const gchar* value);
void data_SearchClips (Data* self,
                       const gchar* term);
static void ___lambda19__window_on_search (Window* _sender,
                                    const gchar* value,
                                    gpointer self);
static void application_finalize (GObject * obj);
static void _vala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);


Application*
application_construct (GType object_type)
{
	Application * self = NULL;
#line 5 "/home/john/ValaTest/src/Application.vala"
	self = (Application*) g_object_new (object_type, "application-id", "com.github.maxx730.test", "flags", G_APPLICATION_FLAGS_NONE, NULL);
#line 4 "/home/john/ValaTest/src/Application.vala"
	return self;
#line 188 "Application.c"
}


Application*
application_new (void)
{
#line 4 "/home/john/ValaTest/src/Application.vala"
	return application_construct (TYPE_APPLICATION);
#line 197 "Application.c"
}


static Block1Data*
block1_data_ref (Block1Data* _data1_)
{
#line 11 "/home/john/ValaTest/src/Application.vala"
	g_atomic_int_inc (&_data1_->_ref_count_);
#line 11 "/home/john/ValaTest/src/Application.vala"
	return _data1_;
#line 208 "Application.c"
}


static void
block1_data_unref (void * _userdata_)
{
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
#line 11 "/home/john/ValaTest/src/Application.vala"
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
#line 219 "Application.c"
		Application* self;
#line 11 "/home/john/ValaTest/src/Application.vala"
		self = _data1_->self;
#line 11 "/home/john/ValaTest/src/Application.vala"
		_g_object_unref0 (_data1_->clipboard);
#line 11 "/home/john/ValaTest/src/Application.vala"
		_g_object_unref0 (_data1_->settings);
#line 11 "/home/john/ValaTest/src/Application.vala"
		_g_object_unref0 (_data1_->dat);
#line 11 "/home/john/ValaTest/src/Application.vala"
		_g_object_unref0 (_data1_->window);
#line 11 "/home/john/ValaTest/src/Application.vala"
		_g_object_unref0 (self);
#line 11 "/home/john/ValaTest/src/Application.vala"
		g_slice_free (Block1Data, _data1_);
#line 235 "Application.c"
	}
}


static void
__lambda13_ (Block1Data* _data1_,
             Clip** newClips,
             int newClips_length1)
{
	Application* self;
	Window* _tmp0_;
#line 18 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 19 "/home/john/ValaTest/src/Application.vala"
	g_print ("ABOUT TO DISPLAY CLIPS\n");
#line 21 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = _data1_->window;
#line 21 "/home/john/ValaTest/src/Application.vala"
	window_DisplayClips (_tmp0_, newClips, newClips_length1);
#line 255 "Application.c"
}


static void
___lambda13__data_row_callback (Data* _sender,
                                Clip** clips,
                                int clips_length1,
                                gpointer self)
{
#line 18 "/home/john/ValaTest/src/Application.vala"
	__lambda13_ (self, clips, clips_length1);
#line 267 "Application.c"
}


static gchar*
bool_to_string (gboolean self)
{
	gchar* result = NULL;
#line 37 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (self) {
#line 277 "Application.c"
		gchar* _tmp0_;
#line 38 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp0_ = g_strdup ("true");
#line 38 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		result = _tmp0_;
#line 38 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return result;
#line 285 "Application.c"
	} else {
		gchar* _tmp1_;
#line 40 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp1_ = g_strdup ("false");
#line 40 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		result = _tmp1_;
#line 40 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return result;
#line 294 "Application.c"
	}
}


static void
__lambda14_ (Block1Data* _data1_,
             gboolean val)
{
	Application* self;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	GSettings* _tmp4_;
#line 28 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 29 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = bool_to_string (val);
#line 29 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = _tmp0_;
#line 29 "/home/john/ValaTest/src/Application.vala"
	_tmp2_ = g_strconcat (_tmp1_, "\n", NULL);
#line 29 "/home/john/ValaTest/src/Application.vala"
	_tmp3_ = _tmp2_;
#line 29 "/home/john/ValaTest/src/Application.vala"
	g_print ("%s", _tmp3_);
#line 29 "/home/john/ValaTest/src/Application.vala"
	_g_free0 (_tmp3_);
#line 29 "/home/john/ValaTest/src/Application.vala"
	_g_free0 (_tmp1_);
#line 30 "/home/john/ValaTest/src/Application.vala"
	_tmp4_ = _data1_->settings;
#line 30 "/home/john/ValaTest/src/Application.vala"
	g_settings_set_boolean (_tmp4_, "initial-run", val);
#line 31 "/home/john/ValaTest/src/Application.vala"
	_data1_->first_run = val;
#line 331 "Application.c"
}


static void
___lambda14__data_callback_event (Data* _sender,
                                  gboolean value,
                                  gpointer self)
{
#line 28 "/home/john/ValaTest/src/Application.vala"
	__lambda14_ (self, value);
#line 342 "Application.c"
}


static gpointer
_g_object_ref0 (gpointer self)
{
#line 44 "/home/john/ValaTest/src/Application.vala"
	return self ? g_object_ref (self) : NULL;
#line 351 "Application.c"
}


static gchar*
string_replace (const gchar* self,
                const gchar* old,
                const gchar* replacement)
{
	gchar* result = NULL;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	GError* _inner_error0_ = NULL;
#line 1477 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1477 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (old != NULL, NULL);
#line 1477 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (replacement != NULL, NULL);
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if ((*((gchar*) self)) == '\0') {
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp1_ = TRUE;
#line 374 "Application.c"
	} else {
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp1_ = (*((gchar*) old)) == '\0';
#line 378 "Application.c"
	}
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (_tmp1_) {
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp0_ = TRUE;
#line 384 "Application.c"
	} else {
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp0_ = g_strcmp0 (old, replacement) == 0;
#line 388 "Application.c"
	}
#line 1478 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (_tmp0_) {
#line 392 "Application.c"
		gchar* _tmp2_;
#line 1479 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp2_ = g_strdup (self);
#line 1479 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		result = _tmp2_;
#line 1479 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return result;
#line 400 "Application.c"
	}
	{
		GRegex* regex = NULL;
		gchar* _tmp3_;
		gchar* _tmp4_;
		GRegex* _tmp5_;
		GRegex* _tmp6_;
		gchar* _tmp7_ = NULL;
		GRegex* _tmp8_;
		gchar* _tmp9_;
		gchar* _tmp10_;
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp3_ = g_regex_escape_string (old, -1);
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp4_ = _tmp3_;
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp5_ = g_regex_new (_tmp4_, 0, 0, &_inner_error0_);
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp6_ = _tmp5_;
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_g_free0 (_tmp4_);
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		regex = _tmp6_;
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			if (_inner_error0_->domain == G_REGEX_ERROR) {
#line 428 "Application.c"
				goto __catch0_g_regex_error;
			}
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			g_clear_error (&_inner_error0_);
#line 1482 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			return NULL;
#line 437 "Application.c"
		}
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp8_ = regex;
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp9_ = g_regex_replace_literal (_tmp8_, self, (gssize) -1, 0, replacement, 0, &_inner_error0_);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp7_ = _tmp9_;
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			_g_regex_unref0 (regex);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			if (_inner_error0_->domain == G_REGEX_ERROR) {
#line 451 "Application.c"
				goto __catch0_g_regex_error;
			}
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			_g_regex_unref0 (regex);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			g_clear_error (&_inner_error0_);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
			return NULL;
#line 462 "Application.c"
		}
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp10_ = _tmp7_;
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp7_ = NULL;
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		result = _tmp10_;
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_g_free0 (_tmp7_);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_g_regex_unref0 (regex);
#line 1483 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return result;
#line 476 "Application.c"
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
		GError* e = NULL;
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		e = _inner_error0_;
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_inner_error0_ = NULL;
#line 1485 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		g_assert_not_reached ();
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_g_error_free0 (e);
#line 490 "Application.c"
	}
	__finally0:
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		g_clear_error (&_inner_error0_);
#line 1481 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		return NULL;
#line 501 "Application.c"
	}
}


static void
__lambda15_ (Block1Data* _data1_,
             GdkEventOwnerChange* event)
{
	Application* self;
	gchar* value = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	Data* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
#line 45 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 45 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (event != NULL);
#line 47 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = gtk_clipboard_wait_for_text (_data1_->clipboard);
#line 47 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = _tmp0_;
#line 47 "/home/john/ValaTest/src/Application.vala"
	_tmp2_ = string_replace (_tmp1_, "'", "\'");
#line 47 "/home/john/ValaTest/src/Application.vala"
	_tmp3_ = _tmp2_;
#line 47 "/home/john/ValaTest/src/Application.vala"
	_g_free0 (_tmp1_);
#line 47 "/home/john/ValaTest/src/Application.vala"
	value = _tmp3_;
#line 50 "/home/john/ValaTest/src/Application.vala"
	_tmp4_ = _data1_->dat;
#line 50 "/home/john/ValaTest/src/Application.vala"
	data_InsertClip (_tmp4_, value);
#line 53 "/home/john/ValaTest/src/Application.vala"
	_tmp5_ = g_strconcat ("'", value, NULL);
#line 53 "/home/john/ValaTest/src/Application.vala"
	_tmp6_ = _tmp5_;
#line 53 "/home/john/ValaTest/src/Application.vala"
	_tmp7_ = g_strconcat (_tmp6_, "' has been saved into your history.", NULL);
#line 53 "/home/john/ValaTest/src/Application.vala"
	_tmp8_ = _tmp7_;
#line 53 "/home/john/ValaTest/src/Application.vala"
	application_Notify (self, "Clip Added", _tmp8_);
#line 53 "/home/john/ValaTest/src/Application.vala"
	_g_free0 (_tmp8_);
#line 53 "/home/john/ValaTest/src/Application.vala"
	_g_free0 (_tmp6_);
#line 45 "/home/john/ValaTest/src/Application.vala"
	_g_free0 (value);
#line 557 "Application.c"
}


static void
___lambda15__gtk_clipboard_owner_change (GtkClipboard* _sender,
                                         GdkEventOwnerChange* event,
                                         gpointer self)
{
#line 45 "/home/john/ValaTest/src/Application.vala"
	__lambda15_ (self, event);
#line 568 "Application.c"
}


static void
__lambda16_ (Block1Data* _data1_,
             Clip* clip)
{
	Application* self;
	Window* _tmp0_;
	Data* _tmp1_;
#line 57 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 57 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (clip != NULL);
#line 58 "/home/john/ValaTest/src/Application.vala"
	g_print ("INSERT CALLBACK\n");
#line 62 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = _data1_->window;
#line 62 "/home/john/ValaTest/src/Application.vala"
	window_ResetClips (_tmp0_);
#line 64 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = _data1_->dat;
#line 64 "/home/john/ValaTest/src/Application.vala"
	data_GetClips (_tmp1_);
#line 593 "Application.c"
}


static void
___lambda16__data_insert_callback (Data* _sender,
                                   Clip* clip,
                                   gpointer self)
{
#line 57 "/home/john/ValaTest/src/Application.vala"
	__lambda16_ (self, clip);
#line 604 "Application.c"
}


static void
__lambda17_ (Block1Data* _data1_,
             const gchar* value)
{
	Application* self;
#line 72 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 72 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (value != NULL);
#line 73 "/home/john/ValaTest/src/Application.vala"
	gtk_clipboard_set_text (_data1_->clipboard, value, g_utf8_strlen (value, (gssize) -1));
#line 619 "Application.c"
}


static void
___lambda17__window_on_clip_select (Window* _sender,
                                    const gchar* value,
                                    gpointer self)
{
#line 72 "/home/john/ValaTest/src/Application.vala"
	__lambda17_ (self, value);
#line 630 "Application.c"
}


static void
__lambda18_ (Block1Data* _data1_)
{
	Application* self;
	Data* _tmp0_;
	Window* _tmp1_;
#line 78 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 79 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = _data1_->dat;
#line 79 "/home/john/ValaTest/src/Application.vala"
	data_DropTable (_tmp0_);
#line 80 "/home/john/ValaTest/src/Application.vala"
	application_Notify (self, "History Cleared", "Clipboard history has been cleared out.");
#line 81 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = _data1_->window;
#line 81 "/home/john/ValaTest/src/Application.vala"
	window_ResetClips (_tmp1_);
#line 652 "Application.c"
}


static void
___lambda18__window_on_clear_data (Window* _sender,
                                   gpointer self)
{
#line 78 "/home/john/ValaTest/src/Application.vala"
	__lambda18_ (self);
#line 662 "Application.c"
}


static void
__lambda19_ (Block1Data* _data1_,
             const gchar* value)
{
	Application* self;
	Window* _tmp0_;
	Data* _tmp1_;
#line 84 "/home/john/ValaTest/src/Application.vala"
	self = _data1_->self;
#line 84 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (value != NULL);
#line 85 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = _data1_->window;
#line 85 "/home/john/ValaTest/src/Application.vala"
	window_ResetClips (_tmp0_);
#line 86 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = _data1_->dat;
#line 86 "/home/john/ValaTest/src/Application.vala"
	data_SearchClips (_tmp1_, value);
#line 685 "Application.c"
}


static void
___lambda19__window_on_search (Window* _sender,
                               const gchar* value,
                               gpointer self)
{
#line 84 "/home/john/ValaTest/src/Application.vala"
	__lambda19_ (self, value);
#line 696 "Application.c"
}


static void
application_real_activate (GApplication* base)
{
	Application * self;
	Block1Data* _data1_;
	Window* _tmp0_;
	Data* _tmp1_;
	GSettings* _tmp2_;
	Data* _tmp3_;
	GSettings* _tmp4_;
	Data* _tmp5_;
	gboolean _tmp6_;
	GdkDisplay* _tmp9_;
	GtkClipboard* _tmp10_;
	GtkClipboard* _tmp11_;
	Data* _tmp12_;
	Window* _tmp13_;
	Window* _tmp14_;
	Window* _tmp15_;
	Window* _tmp16_;
#line 11 "/home/john/ValaTest/src/Application.vala"
	self = (Application*) base;
#line 11 "/home/john/ValaTest/src/Application.vala"
	_data1_ = g_slice_new0 (Block1Data);
#line 11 "/home/john/ValaTest/src/Application.vala"
	_data1_->_ref_count_ = 1;
#line 11 "/home/john/ValaTest/src/Application.vala"
	_data1_->self = g_object_ref (self);
#line 12 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = window_new ((GtkApplication*) self);
#line 12 "/home/john/ValaTest/src/Application.vala"
	g_object_ref_sink (_tmp0_);
#line 12 "/home/john/ValaTest/src/Application.vala"
	_data1_->window = _tmp0_;
#line 13 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = data_new ();
#line 13 "/home/john/ValaTest/src/Application.vala"
	_data1_->dat = _tmp1_;
#line 14 "/home/john/ValaTest/src/Application.vala"
	_tmp2_ = g_settings_new ("com.github.Maxx730.kcopy");
#line 14 "/home/john/ValaTest/src/Application.vala"
	_data1_->settings = _tmp2_;
#line 18 "/home/john/ValaTest/src/Application.vala"
	_tmp3_ = _data1_->dat;
#line 18 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_tmp3_, "row-callback", (GCallback) ___lambda13__data_row_callback, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 26 "/home/john/ValaTest/src/Application.vala"
	_tmp4_ = _data1_->settings;
#line 26 "/home/john/ValaTest/src/Application.vala"
	_data1_->first_run = g_settings_get_boolean (_tmp4_, "initial-run");
#line 28 "/home/john/ValaTest/src/Application.vala"
	_tmp5_ = _data1_->dat;
#line 28 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_tmp5_, "callback-event", (GCallback) ___lambda14__data_callback_event, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 34 "/home/john/ValaTest/src/Application.vala"
	_tmp6_ = _data1_->first_run;
#line 34 "/home/john/ValaTest/src/Application.vala"
	if (!_tmp6_) {
#line 758 "Application.c"
		Data* _tmp7_;
#line 35 "/home/john/ValaTest/src/Application.vala"
		_tmp7_ = _data1_->dat;
#line 35 "/home/john/ValaTest/src/Application.vala"
		data_CreateTable (_tmp7_);
#line 764 "Application.c"
	} else {
		Data* _tmp8_;
#line 38 "/home/john/ValaTest/src/Application.vala"
		_tmp8_ = _data1_->dat;
#line 38 "/home/john/ValaTest/src/Application.vala"
		data_GetClips (_tmp8_);
#line 771 "Application.c"
	}
#line 44 "/home/john/ValaTest/src/Application.vala"
	_tmp9_ = gdk_display_get_default ();
#line 44 "/home/john/ValaTest/src/Application.vala"
	_tmp10_ = gtk_clipboard_get_for_display (_tmp9_, GDK_SELECTION_CLIPBOARD);
#line 44 "/home/john/ValaTest/src/Application.vala"
	_tmp11_ = _g_object_ref0 (_tmp10_);
#line 44 "/home/john/ValaTest/src/Application.vala"
	_data1_->clipboard = _tmp11_;
#line 45 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_data1_->clipboard, "owner-change", (GCallback) ___lambda15__gtk_clipboard_owner_change, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 57 "/home/john/ValaTest/src/Application.vala"
	_tmp12_ = _data1_->dat;
#line 57 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_tmp12_, "insert-callback", (GCallback) ___lambda16__data_insert_callback, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 72 "/home/john/ValaTest/src/Application.vala"
	_tmp13_ = _data1_->window;
#line 72 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_tmp13_, "on-clip-select", (GCallback) ___lambda17__window_on_clip_select, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 78 "/home/john/ValaTest/src/Application.vala"
	_tmp14_ = _data1_->window;
#line 78 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_tmp14_, "on-clear-data", (GCallback) ___lambda18__window_on_clear_data, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 84 "/home/john/ValaTest/src/Application.vala"
	_tmp15_ = _data1_->window;
#line 84 "/home/john/ValaTest/src/Application.vala"
	g_signal_connect_data (_tmp15_, "on-search", (GCallback) ___lambda19__window_on_search, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 90 "/home/john/ValaTest/src/Application.vala"
	_tmp16_ = _data1_->window;
#line 90 "/home/john/ValaTest/src/Application.vala"
	gtk_application_add_window ((GtkApplication*) self, (GtkWindow*) _tmp16_);
#line 11 "/home/john/ValaTest/src/Application.vala"
	block1_data_unref (_data1_);
#line 11 "/home/john/ValaTest/src/Application.vala"
	_data1_ = NULL;
#line 807 "Application.c"
}


void
application_Notify (Application* self,
                    const gchar* title,
                    const gchar* message)
{
	GNotification* notif = NULL;
	GNotification* _tmp0_;
	GThemedIcon* _tmp1_;
	GThemedIcon* _tmp2_;
#line 94 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (self != NULL);
#line 94 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (title != NULL);
#line 94 "/home/john/ValaTest/src/Application.vala"
	g_return_if_fail (message != NULL);
#line 95 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = g_notification_new (title);
#line 95 "/home/john/ValaTest/src/Application.vala"
	notif = _tmp0_;
#line 96 "/home/john/ValaTest/src/Application.vala"
	g_notification_set_body (notif, message);
#line 97 "/home/john/ValaTest/src/Application.vala"
	_tmp1_ = (GThemedIcon*) g_themed_icon_new ("process-completed");
#line 97 "/home/john/ValaTest/src/Application.vala"
	_tmp2_ = _tmp1_;
#line 97 "/home/john/ValaTest/src/Application.vala"
	g_notification_set_icon (notif, (GIcon*) _tmp2_);
#line 97 "/home/john/ValaTest/src/Application.vala"
	_g_object_unref0 (_tmp2_);
#line 98 "/home/john/ValaTest/src/Application.vala"
	g_application_send_notification ((GApplication*) self, "kcopy.app", notif);
#line 94 "/home/john/ValaTest/src/Application.vala"
	_g_object_unref0 (notif);
#line 844 "Application.c"
}


static void
application_class_init (ApplicationClass * klass)
{
#line 1 "/home/john/ValaTest/src/Application.vala"
	application_parent_class = g_type_class_peek_parent (klass);
#line 1 "/home/john/ValaTest/src/Application.vala"
	g_type_class_add_private (klass, sizeof (ApplicationPrivate));
#line 1 "/home/john/ValaTest/src/Application.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) application_real_activate;
#line 1 "/home/john/ValaTest/src/Application.vala"
	G_OBJECT_CLASS (klass)->finalize = application_finalize;
#line 859 "Application.c"
}


static void
application_instance_init (Application * self)
{
	Clip** _tmp0_;
#line 1 "/home/john/ValaTest/src/Application.vala"
	self->priv = APPLICATION_GET_PRIVATE (self);
#line 2 "/home/john/ValaTest/src/Application.vala"
	_tmp0_ = g_new0 (Clip*, 0 + 1);
#line 2 "/home/john/ValaTest/src/Application.vala"
	self->priv->clips = _tmp0_;
#line 2 "/home/john/ValaTest/src/Application.vala"
	self->priv->clips_length1 = 0;
#line 2 "/home/john/ValaTest/src/Application.vala"
	self->priv->_clips_size_ = self->priv->clips_length1;
#line 877 "Application.c"
}


static void
application_finalize (GObject * obj)
{
	Application * self;
#line 1 "/home/john/ValaTest/src/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_APPLICATION, Application);
#line 2 "/home/john/ValaTest/src/Application.vala"
	self->priv->clips = (_vala_array_free (self->priv->clips, self->priv->clips_length1, (GDestroyNotify) clip_unref), NULL);
#line 1 "/home/john/ValaTest/src/Application.vala"
	G_OBJECT_CLASS (application_parent_class)->finalize (obj);
#line 891 "Application.c"
}


GType
application_get_type (void)
{
	static volatile gsize application_type_id__volatile = 0;
	if (g_once_init_enter (&application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Application), 0, (GInstanceInitFunc) application_instance_init, NULL };
		GType application_type_id;
		application_type_id = g_type_register_static (gtk_application_get_type (), "Application", &g_define_type_info, 0);
		g_once_init_leave (&application_type_id__volatile, application_type_id);
	}
	return application_type_id__volatile;
}


static void
_vala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void
_vala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



