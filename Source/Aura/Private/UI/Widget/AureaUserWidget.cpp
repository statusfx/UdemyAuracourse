// StatusFXGaming


#include "UI/Widget/AureaUserWidget.h"

#include "UI/WidgetController/AuraWidgetController.h"

void UAureaUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
