#pragma once

#ifndef ATOM_JS_DEFINITIONS_HEADER
#define ATOM_JS_DEFINITIONS_HEADER

#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>

#ifdef __cplusplus
#define ATOM_JS_DEFINITION extern "C"
#else
#define ATOM_JS_DEFINITION
#endif

#define ATOM_HEAD_ELEMENT_REFERENCE 1
#define ATOM_BODY_ELEMENT_REFERNECE 2

#define ATOM_EVENT_FUNCTION_NAME "8&f7&j$+ea63i^["
#define ATOM_EVENT_VARIABLE(event) ATOM_JS_VARIABLE::take_ownership(event)

#define ATOM_AS(variable) .as<variable>()
#define ATOM_AS_STRING ATOM_AS(std::string)
#define ATOM_AS_CSTRING ATOM_AS(char*)
#define ATOM_AS_POINTER ATOM_AS(void*)
#define ATOM_AS_INT ATOM_AS(int)
#define ATOM_AS_FLOAT ATOM_AS(float)
#define ATOM_AS_DOUBLE ATOM_AS(double)
#define ATOM_AS_LONG ATOM_AS(long)
#define ATOM_AS_LONGLONG ATOM_AS(long long)
#define ATOM_AS_UINT ATOM_AS(unsigned int)
#define ATOM_AS_ULONG ATOM_AS(unsigned long)
#define ATOM_AS_ULONGLONG ATOM_AS(unsigned long long)
#define ATOM_AS_UNSIGNED ATOM_AS(unsigned)
#define ATOM_AS_ELEMENT ATOM_AS(ATOM_ELEMENT_REFERENCE)

#define ATOM_STRING std::string() =

#define ATOM_JS EM_ASYNC_JS

#define ATOM_LOAD_STRING(process, code) atom_loadstring_child_process(process, "" #code "")
#define ATOM_ASM(process, code) atom_eval_child_process(process, "" #code "")
#define ATOM_DIRECT_ASM EM_ASM_PTR

#define ATOM_SHARED_FUNCTION_TYPE(type, ...) typedef ATOM_SHARED_FUNCTION_RETURN (*type)(__VA_ARGS__)
#define ATOM_SHARED_FUNCTION(...) [](__VA_ARGS__) -> ATOM_SHARED_FUNCTION_RETURN

typedef unsigned long long ATOM_TICK;

typedef unsigned long ATOM_ELEMENT_REFERENCE;
typedef std::vector<ATOM_ELEMENT_REFERENCE> ATOM_ELEMENT_REFERENCE_LIST;

typedef void* ATOM_POINTER;
typedef unsigned long long ATOM_POINTER_REFERENCE;
typedef ATOM_POINTER ATOM_FUNCTION;

typedef emscripten::EM_VAL ATOM_JS_VARIABLE_HANDLE;
typedef ATOM_JS_VARIABLE_HANDLE ATOM_EVENT;
typedef emscripten::val ATOM_JS_VARIABLE;
typedef void (*ATOM_EVENT_HANDLER)(ATOM_EVENT);

typedef void ATOM_SHARED_FUNCTION_RETURN;

typedef unsigned long ATOM_ANIMATION_FRAME;
typedef void (*ATOM_ANIMATION_FRAME_HANDLER)(ATOM_TICK, ATOM_POINTER);

struct ATOM_BOUNDING_BOX {
	double x;
	double y;
	double width;
	double height;
	double left;
	double top;
	double right;
	double bottom;
};

ATOM_JS_DEFINITION void atom_sleep(unsigned int ms);

ATOM_JS_DEFINITION ATOM_TICK atom_get_now();

ATOM_JS_DEFINITION void atom_clear_console();

ATOM_JS_DEFINITION void atom_application_init();

ATOM_JS_DEFINITION char* atom_get_main_script_path();
ATOM_JS_DEFINITION char* atom_get_worker_script_path();

ATOM_JS_DEFINITION bool atom_is_inside_worker();

ATOM_JS_DEFINITION unsigned int _atom_get_temp_value();

ATOM_JS_DEFINITION ATOM_ELEMENT_REFERENCE atom_get_document_head();
ATOM_JS_DEFINITION ATOM_ELEMENT_REFERENCE atom_get_document_body();

ATOM_JS_DEFINITION ATOM_ELEMENT_REFERENCE atom_create_element(const char* type);
ATOM_JS_DEFINITION bool                   atom_element_exists(ATOM_ELEMENT_REFERENCE element);
ATOM_JS_DEFINITION void                   atom_destroy_element(ATOM_ELEMENT_REFERENCE element);
ATOM_JS_DEFINITION void                   atom_free_element(ATOM_ELEMENT_REFERENCE element);
ATOM_JS_DEFINITION bool                   atom_is_same_element(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target);
ATOM_JS_DEFINITION void                   atom_set_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute, const char* value);
ATOM_JS_DEFINITION char*                  atom_get_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute);
ATOM_JS_DEFINITION void                   atom_set_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value);
ATOM_JS_DEFINITION char*                  atom_get_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName);
ATOM_JS_DEFINITION void                   atom_element_append_child(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target);
ATOM_JS_DEFINITION void                   atom_set_element_style(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value);
ATOM_JS_DEFINITION char*                  atom_get_element_style(ATOM_ELEMENT_REFERENCE element, const char* propertyName);
ATOM_JS_DEFINITION void                   atom_add_element_class(ATOM_ELEMENT_REFERENCE element, const char* className);
ATOM_JS_DEFINITION bool                   atom_element_class_exists(ATOM_ELEMENT_REFERENCE element, const char* className);
ATOM_JS_DEFINITION void                   atom_remove_element_class(ATOM_ELEMENT_REFERENCE element, const char* className);
ATOM_JS_DEFINITION char*                  atom_get_element_node_name(ATOM_ELEMENT_REFERENCE element);
ATOM_JS_DEFINITION ATOM_ELEMENT_REFERENCE atom_get_element_parent(ATOM_ELEMENT_REFERENCE element);

ATOM_JS_DEFINITION bool          atom_is_function_registered(const char* name);
ATOM_JS_DEFINITION void          atom_unregister_function(const char* name);
ATOM_JS_DEFINITION ATOM_FUNCTION atom_get_function(const char* name);

ATOM_JS_DEFINITION bool  atom_is_multi_thread_enabled();
ATOM_JS_DEFINITION char* atom_get_process_name();
ATOM_JS_DEFINITION bool  atom_is_main_process();

ATOM_JS_DEFINITION void                    atom_fork(const char* name);
ATOM_JS_DEFINITION void                    atom_post_child_process(const char* name, ATOM_JS_VARIABLE_HANDLE data);
ATOM_JS_DEFINITION bool                    atom_child_process_exists(const char* name);
ATOM_JS_DEFINITION bool                    atom_child_process_is_ready(const char* name);
ATOM_JS_DEFINITION void                    atom_wait_till_process_be_ready(const char* name);
ATOM_JS_DEFINITION void                    atom_terminate_child_process(const char* name);
ATOM_JS_DEFINITION ATOM_FUNCTION           atom_loadstring_child_process(const char* name, const char* code);
ATOM_JS_DEFINITION ATOM_JS_VARIABLE_HANDLE atom_eval_child_process(const char* name, const char* code);

ATOM_JS_DEFINITION void atom_yield();
ATOM_JS_DEFINITION void atom_resume(const char* name);

ATOM_JS_DEFINITION bool atom_function_pointer_exists(ATOM_FUNCTION func);
ATOM_JS_DEFINITION void atom_delete_function_pointer(ATOM_FUNCTION func);

ATOM_JS_DEFINITION void          atom_register_shared_function(const char* name, ATOM_FUNCTION func, bool clearMemory);
ATOM_JS_DEFINITION bool          atom_shared_function_exists(const char* name);
ATOM_JS_DEFINITION void          atom_remove_shared_function(const char* name);
ATOM_JS_DEFINITION char*         atom_get_shared_function_process(const char* name);
ATOM_JS_DEFINITION ATOM_FUNCTION atom_get_shared_function(const char* name);

ATOM_JS_DEFINITION void                   atom_allocate_shared_memory(const char* name, size_t size);
ATOM_JS_DEFINITION bool                   atom_shared_memory_exists(const char* name);
ATOM_JS_DEFINITION ATOM_POINTER_REFERENCE atom_get_shared_memory_pointer(const char* name);
ATOM_JS_DEFINITION size_t                 atom_get_shared_memory_size(const char* name);
ATOM_JS_DEFINITION void                   atom_free_shared_memory(const char* name);
ATOM_JS_DEFINITION ATOM_POINTER           atom_get_shared_memory(const char* name);
ATOM_JS_DEFINITION void                   atom_update_shared_memory(const char* name, const char* process);
ATOM_JS_DEFINITION void                   atom_update_main_shared_memory(const char* name);

ATOM_JS_DEFINITION ATOM_POINTER           atom_get_pointer_from_reference(ATOM_POINTER_REFERENCE reference);
ATOM_JS_DEFINITION ATOM_POINTER_REFERENCE atom_get_pointer_reference(ATOM_POINTER pointer);

ATOM_JS_DEFINITION ATOM_ANIMATION_FRAME         atom_request_animation_frame(ATOM_ANIMATION_FRAME_HANDLER handler, ATOM_POINTER value);
ATOM_JS_DEFINITION bool                         atom_exists_animation_frame(ATOM_ANIMATION_FRAME id);
ATOM_JS_DEFINITION void                         atom_cancel_animation_frame(ATOM_ANIMATION_FRAME id);
ATOM_JS_DEFINITION ATOM_ANIMATION_FRAME_HANDLER atom_get_animation_frame_handler(ATOM_ANIMATION_FRAME id);

ATOM_ELEMENT_REFERENCE atom_query_selector(const char* query);
ATOM_ELEMENT_REFERENCE atom_query_selector(ATOM_ELEMENT_REFERENCE element, const char* query);

ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(const char* query);
ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(ATOM_ELEMENT_REFERENCE element, const char* query);

void atom_free_element_list(const ATOM_ELEMENT_REFERENCE_LIST list);

void atom_register_function(const char* name, ATOM_FUNCTION handler);

char* atom_generage_random_key(const int& count);

ATOM_BOUNDING_BOX atom_get_element_bounding_box(ATOM_ELEMENT_REFERENCE element);

void atom_add_event_listener(const char* eventName, ATOM_EVENT_HANDLER handler);
void atom_add_event_listener(ATOM_ELEMENT_REFERENCE element, const char* eventName, ATOM_EVENT_HANDLER handler);

void atom_exit(int status);

#endif