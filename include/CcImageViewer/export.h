#ifndef CC_IMAGE_VIEWER_EXPORT_H
#define CC_IMAGE_VIEWER_EXPORT_H

#ifdef MAKE_CCIMAGEVIEWER_DLL
#define IMGVIEWER_API __declspec(dllexport)
#else
#define IMGVIEWER_API __declspec(dllimport)
#endif // MAKE_CCIMAGEVIEWER_DLL

#endif