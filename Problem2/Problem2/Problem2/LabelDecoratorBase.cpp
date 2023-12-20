#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		LabelDecoratorBase::LabelDecoratorBase(unique_ptr<Label> next)
		{
			if (next == nullptr)
				throw invalid_argument("Reference to decorated object cannot be nullptr");
			m_label = std::move(next);
		}

		unique_ptr<Label> LabelDecoratorBase::removeDecoratorFrom(unique_ptr<Label> from,
			const type_info& decoratorType)
		{
			LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(from.get());
			if (decorator)
				return decorator->removeDecorator(decoratorType);

			return std::move(from);
		}
	}
}
